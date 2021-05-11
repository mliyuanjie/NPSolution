#include "npsio.h"
#include "datmodel.h"


DATModel::~DATModel() {
	dat.close();
}

void DATModel::load(std::string f) {
	sigs.clear();
	data_smooth.clear();
	data_smooth.shrink_to_fit();
	emit sendData_f(QVector<QPointF>(), 0, 0);
	fn = f;
	dat.open(fn);
	interval = dat.interval();
	n = dat.size();
	float xmin = 0;
	float xmax = dat.size() * interval / 1000;
	std::pair<float, float> y = dat.valminmax();
	float ymax = std::max(y.first, y.second);
	float ymin = std::min(y.first, y.second);
	emit sendAxis(xmin, xmax, ymin - 3 * (ymax - ymin), ymax + 3 * (ymax - ymin));
	return;
}

void DATModel::home() {
	float xmin = 0;
	float xmax = n * interval / 1000;
	std::pair<float, float> y = dat.valminmax();
	float ymax = std::max(y.first, y.second);
	float ymin = std::min(y.first, y.second);
	emit sendAxis(xmin, xmax, ymin - 3 * (ymax - ymin), ymax + 3 * (ymax - ymin));
	return;
}

void DATModel::save(QVector<QPointF> point) {
	std::string fnout = "_cut.dat";
	fnout.insert(0, fn, 0, fn.size() - 4);
	std::ofstream file;
	file.open(fnout, std::fstream::app | std::ios::binary);
	float r = interval / 1000;
	file.write(reinterpret_cast<char*>(&r), sizeof(float));
	int s, e;
	for (int i = 0; i < point.size(); i++) {
		s = point[i].x() * 1000 / interval;
		e = point[i].y() * 1000 / interval;
		std::vector<float> res = std::move(dat.data(s, e, 1));
		file.write(reinterpret_cast<char*>(res.data()), res.size() * sizeof(float));
	}
	file.close();
	return;
}

void DATModel::draw(double xmin, double xmax) {
	unsigned int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
	unsigned int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >=0) ? xmax * 1000 / interval : n;
	unsigned int skip = (e-s) / 1500;
	unsigned int j;
	QVector<QPointF> point;	
	if (skip <= 1) {
		for (unsigned int i = s; i < e; i += 1) {
			point.append(QPointF((double)i * interval / 1000, dat.at(i)));
		}
	}
	else {
		for (unsigned int i = s; i < e; i += skip) {
			j = (i + skip <= e) ? i + skip : e;
			std::pair<float, float> x = dat.valminmax(i, j);
			point.append(QPointF(i * interval / 1000, x.first));
			point.append(QPointF(i * interval / 1000, x.second));
		}
	}
	emit sendData(point);
	point.clear();
	if (!data_smooth.empty()) {
		for (unsigned int i = s; i < e; i += skip) {
			j = (i + skip <= e) ? i + skip : e;
			auto pos = std::minmax_element(data_smooth.begin() + i, data_smooth.begin() + j);
			point.append(QPointF(i * interval / 1000, *pos.first));
			point.append(QPointF(i * interval / 1000, *pos.second));
		}
		emit sendData_f(point, 0, 0);
	}
	return;
}

void DATModel::signal(float sigma, float freq, float thres) {
	data_smooth.clear();
	data_smooth.shrink_to_fit();
	gsl_vector* data = gsl_vector_alloc(n);
	std::vector<float> t = std::move(dat.data());
	for (int i = 0; i < t.size(); i++)
		gsl_vector_set(data, i, t[i]);
	t.clear();
	gsl_vector* tmp;
	if (sigma == 0)
		tmp = meanSmooth(data, freq);
	else
		tmp = gaussSmooth(data, sigma, freq);
	emit sendProcess(50);
	double mean, sd;
	sigs = findPeak(tmp->data, tmp->size, thres, sd, mean);
	QVector<QPointF> point;
	float val;
	unsigned s, e;
	for (int i = 0; i < sigs.size(); i++) {
		s = sigs[i].start;
		e = sigs[i].end;
		point.append(QPointF(s * interval / 1000, sigs[i].currentbase));
		point.append(QPointF(s * interval / 1000, sigs[i].currentmax));
		point.append(QPointF(e * interval / 1000, sigs[i].currentmax));
		point.append(QPointF(e * interval / 1000, sigs[i].currentbase));
	}
	emit sendProcess(90);
	emit sendData_f(point, mean, sd);
	gsl_vector_free(tmp);
	gsl_vector_free(data);
	emit sendProcess(100);
}

void DATModel::savenps(float a, float b, float c, float d) {
	std::string filename(fn.substr(0, fn.find_last_of("/")) + std::string("/result.nps"));
	NPSIO file;
	file.load(filename);
	Para para = { a, b, c, interval, d};
	file.push(fn, para, sigs.data(), sigs.size());
	file.save(filename);
	emit sendProcess(0);
}

void DATModel::removenps() {
	std::string filename(fn.substr(0, fn.find_last_of("/")) + std::string("/result.nps"));
	NPSIO file;
	file.load(filename);
	file.remove(fn);
	file.save(filename);
	emit sendProcess(100);
}

void DATModel::lowpass(float sigma, float freq) {
	gsl_vector* data = gsl_vector_alloc(n);
	data_smooth = std::move(dat.data());
	for (int i = 0; i < data_smooth.size(); i++)
		gsl_vector_set(data, i, data_smooth[i]);
	gsl_vector* tmp;
	if (sigma == 0)
		tmp = meanSmooth(data, freq);
	else
		tmp = gaussSmooth(data, sigma, freq);
	for (int i = 0; i < n; i++)
		data_smooth[i] = gsl_vector_get(tmp, i);
	gsl_vector_free(tmp);
	gsl_vector_free(data);
	home();
}

void DATModel::setinterval(float a) {
	interval = 1 / a * 1000;
	home();
}