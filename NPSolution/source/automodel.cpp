#include "npsio.h"
#include "automodel.h" 

AUTOModel::~AUTOModel() {
	dat.close();
}

void AUTOModel::load(std::vector<std::string> f) {
	fn = f;
	home();
	return;
}

void AUTOModel::signal(float sigma, float freq, float thres, float inter, QString qfn) {
	std::string filename(fn[0].substr(0, fn[0].find_last_of("/") + 1) + qfn.toStdString());
	NPSIO file;
	file.load(filename);
	gsl_vector* tmp;
	gsl_vector* data;
	interval = 1 / inter * 1000;
	for (int i = 0; i < fn.size(); i++) {
		dat.open(fn[i]);
		data = gsl_vector_alloc(n);
		std::vector<float> t = std::move(dat.data());
		for (int i = 0; i < t.size(); i++)
			gsl_vector_set(data, i, t[i]);
		t.clear();
		if (sigma == 0)
			tmp = meanSmooth(data, freq);
		else
			tmp = gaussSmooth(data, sigma, freq);
		double mean, sd;
		sigs = findPeak(tmp->data, tmp->size, thres, sd, mean);
		Para para = { sigma, freq, thres, interval, sd };
		file.push(fn[i], para, sigs.data(), sigs.size());
		emit sendBaseline(mean);
		emit sendDev(sd);
		emit sendProcess((float)i / fn.size() * 100);
		gsl_vector_free(tmp);
		gsl_vector_free(data);
	}
	file.save(filename);
	emit sendProcess(0);
}

void AUTOModel::setindex(int n) {
	index = n;
	home();
	return;
}

void AUTOModel::draw(float xmin, float xmax) {
	unsigned int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
	unsigned int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
	unsigned int skip = (e - s) / 1500;
	skip = (skip == 0) ? 1 : skip;
	unsigned int j;
	QVector<QPointF> point;
	for (unsigned int i = s; i < e; i += skip) {
		j = (i + skip <= e) ? i + skip : e;
		std::pair<float, float> x = dat.valminmax(i, j);
		point.append(QPointF(i * interval / 1000, x.first));
		point.append(QPointF(i * interval / 1000, x.second));
	}
	emit sendData(point);
}

void AUTOModel::home() {
	emit sendPath(QString().fromStdString(fn[index]));
	dat.open(fn[index]);
	n = dat.size();
	float xmin = 0;
	float xmax = dat.size() * interval / 1000;
	std::pair<float, float> y = dat.valminmax();
	float ymax = std::max(y.first, y.second);
	float ymin = std::min(y.first, y.second);
	emit sendAxis(xmin, xmax, ymin - 3 * (ymax - ymin), ymax + 3 * (ymax - ymin), true);
	emit sendNum(QString::number(fn.size()));
	emit sendIndex(QString::number(index));
	draw(xmin, xmax);
	return;
}
void AUTOModel::remove() {
	fn.erase(fn.begin() + index);
	if (fn.size() == 0)
		return;
	if (index >= fn.size())
		index--;
	home();
}

void AUTOModel::pretrace() {
	if (index == 0)
		return;
	index--;
	home();
}

void AUTOModel::nexttrace() {
	if (index >= fn.size()-1)
		return;
	index++;
	home();
}