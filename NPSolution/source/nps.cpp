#include "nps.h" 
#include <gsl/gsl_histogram.h>
#include <QtWidgets/qmessagebox.h>
#include "npsio.h"


NPS::~NPS() {
	//NanoporeFitTerminate();
	//mclTerminateApplication();
}

void NPS::load(std::string f) {
	fn = f;
	const char* args[] = { "-nojvm" };
	const int count = sizeof(args) / sizeof(args[0]);
	mclInitializeApplication(args, count);
	if (fn.substr(fn.length() - 3, 3) == "mat") {
		MATFile* pmatFile = NULL;
		mxArray* pMxArray = NULL;
		pmatFile = matOpen(fn.c_str(), "u");
		int M, N;
		size_t strlen;
		int start, len;
		pMxArray = matGetVariable(pmatFile, "PeaksAll");
		M = (int)mxGetM(pMxArray);
		N = (int)mxGetN(pMxArray);
		for (int i = 0; i < M; i++) {			
			mxArray* matcell = mxGetCell(mxGetCell(pMxArray, i),0);
			char* matfn = mxArrayToString(matcell);
			std::string cppfn(matfn);
			std::string filename = fn.substr(0, fn.find_last_of("/") + 1) + cppfn.substr(0, cppfn.find_last_of(","));
			std::string strstart = cppfn.substr(cppfn.find_last_of(",") + 1, cppfn.size() - cppfn.find_last_of(",") - 1);
			start = std::stoi(strstart);
			len = mxGetM(mxGetCell(mxGetCell(pMxArray, i + M),0));
			Peak peak = { start, start + len };
			siglist.push_back(peak);
			if (mymap.find(filename) == mymap.end()) {
				filelist.push_back(filename);
				Para para = { 0,0,0,2 };
				paralist.push_back(para);
				mymap[filename] = std::pair<int, int>(siglist.size()-1, siglist.size());
			}
			else {
				mymap[filename].second++;
			}	
			mxFree(matfn);
		}
		matClose(pmatFile);
	}
	else if (fn.substr(fn.length() - 3, 3) == "nps") {
		NPSIO f;
		f.load(fn);
		filelist = f.filelist;
		paralist = f.paralist;
		siglist = f.siglist;
		mymap = f.mymap;
	}
	return;
}

void NPS::initui() {
	emit sendmessage(QString("Initializing matlab runtime..."));
	IntraEventFitInitialize();
	emit sendmessage(QString("Analysing..."));
	anall();
	emit sendmessage(QString(" "));
	if (filelist.size() > 0) {
		counter = 0;
		loaddata();
		hist(0, 50);
		emit sendtracenum(filelist.size() - 1);
		emit sendsignum(siglist.size() - 1);
	}
}

void NPS::trace(float xmin, float xmax) {
	size_t n = dat.size();
	unsigned int s = (xmin * 1000 / interval >= 0) ? xmin * 1000 / interval : 0;
	unsigned int e = (xmax * 1000 / interval <= n && xmax * 1000 / interval >= 0) ? xmax * 1000 / interval : n;
	unsigned int skip = (e - s) / 1500;
	skip = (skip == 0) ? 1 : skip;
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
	emit sendtrace(point);
	return;
}

void NPS::loaddata() {
	std::string suffix = filelist[counter].substr(filelist[counter].size() - 3, 3);
	std::string a = filelist[counter];
	interval = paralist[counter].interval;
	int size;
	if (suffix != std::string("dat")) 
		return;
	dat.open(a);
	size = dat.size();
	float xmin = 0;
	float xmax = size * interval / 1000;
	float ymin = dat.valmin(0, size);
	float ymax = dat.valmax(0, size);
	emit sendaxis(xmin, xmax, ymin - (ymax - ymin), ymax + (ymax - ymin), true);
	trace(xmin, xmax);
	QVector<QPointF> r;
	int start, end;
	for (int i = mymap[filelist[counter]].first; i < mymap[filelist[counter]].second; i++) {
		start = siglist[i].start;
		end = siglist[i].end;
		r.push_back(QPointF(start * interval / 1000, siglist[i].currentbase));
		r.push_back(QPointF(start * interval / 1000, siglist[i].currentmax));
		r.push_back(QPointF(end * interval / 1000, siglist[i].currentmax));
		r.push_back(QPointF(end * interval / 1000, siglist[i].currentbase));
	}	
	emit sendsig(r);
	emit sendtracecur(counter);
	emit sendDev(paralist[counter].stdDev);
	return;
}

void NPS::fit() {
	if (index >= 0) {
		size_t start, end;
		Peak& peak = siglist[index];
		if ((peak.currentbase - peak.currentmax) / peak.currentbase < fitpara.ileft || (peak.currentbase - peak.currentmax) / peak.currentbase > fitpara.iright)
			return;
		start = peak.start;
		end = peak.end;
		if (end - start <= 2)
			return;
		mwArray mdata(1, end - start + 1, mxDOUBLE_CLASS, mxREAL);
		double* data = new double[end - start + 1];
		for (int i = 0; i < end - start + 1; i++) {
			data[i] = (peak.currentbase - dat.at(i + start)) / peak.currentbase * 10000;
		}
		mdata.SetData(data, end - start + 1);
		mwArray margs(1, 9, mxDOUBLE_CLASS);
		double args[9] = { Efield(physical), fitpara.noise0, fitpara.noise1, fitpara.noise2, fitpara.dipole0,fitpara.dipole1,fitpara.dipole2,fitpara.imin, fitpara.imax };
		margs.SetData(args, 9);
		mwArray mcoef;
		mwArray mdatax;
		mwArray mdatay;
		IntraEventFit(3, mdatax, mdatay, mcoef, mdata, margs);
		double datax[40];
		mdatax.GetData(datax, 40);
		double datay[40];
		mdatay.GetData(datay, 40);
		double coef[5];
		mcoef.GetData(coef, 5);
		QVector<QPointF> r;
		for (int i = 0; i < 40; i++) {
			r.push_back(QPointF(datax[i], datay[i]));
		}
		peak.Imin = coef[0];
		peak.Imax = coef[1];
		peak.residues = coef[4];
		float shape_o, shape_p, vol_o, vol_p;
		float g = gvalue(physical);
		if (m_o.empty()) {
			m_o = std::vector<float>(999);
			m_p = std::vector<float>(999);
			y_o = std::vector<float>(999);
			y_p = std::vector<float>(999);
			oblate(m_o, y_o);
			prolate(m_p, y_p);
		}
		volum_shape(shape_o, vol_o, shape_p, vol_p, peak.Imin, peak.Imax, g, m_o, y_o, m_p, y_p);
		if (fitpara.oblate) {
			peak.shape = shape_o;
			peak.volume = vol_o;
		}
		else {
			peak.shape = shape_p;
			peak.volume = vol_p;
		}
		PeakResult pr = { peak.shape, peak.volume, peak.Imin, peak.Imax, peak.residues, peak.score, (peak.end - peak.start) * interval / 1000};
		emit sendpara(pr);
		emit sendfit(r);
		delete[] data;
	}
	if (index < 0) {
		std::vector<double> data_tmp;
		for (int i = 0; i < siglist.size(); i++) {
			size_t start, end;
			Peak& peak = siglist[i];
			start = peak.start;
			end = peak.end;
			if ((end - start) > fitpara.mint)
				data_tmp.push_back((peak.currentbase - peak.currentmax) / peak.currentbase * 10000);
		}
		mwArray mdata(1, data_tmp.size(), mxDOUBLE_CLASS, mxREAL);
		double* data = data_tmp.data();
		mdata.SetData(data, data_tmp.size());
		mwArray margs(1, 9, mxDOUBLE_CLASS);
		double args[9] = { Efield(physical), fitpara.noise0, fitpara.noise1, fitpara.noise2, fitpara.dipole0,fitpara.dipole1,fitpara.dipole2,fitpara.imin, fitpara.imax };
		margs.SetData(args, 9);
		mwArray mcoef;
		mwArray mdatax;
		mwArray mdatay;
		IntraEventFit(3, mdatax, mdatay, mcoef, mdata, margs);
		double datax[40];
		mdatax.GetData(datax, 40);
		double datay[40];
		mdatay.GetData(datay, 40);
		double coef[5];
		mcoef.GetData(coef, 5);
		QVector<QPointF> r;
		for (int i = 0; i < 40; i++) {
			r.push_back(QPointF(datax[i], datay[i]));
		}
		float shape_o, shape_p, vol_o, vol_p;
		float g = gvalue(physical);
		if (m_o.empty()) {
			m_o = std::vector<float>(999);
			m_p = std::vector<float>(999);
			y_o = std::vector<float>(999);
			y_p = std::vector<float>(999);
			oblate(m_o, y_o);
			prolate(m_p, y_p);
		}
		volum_shape(shape_o, vol_o, shape_p, vol_p, coef[0], coef[1], g, m_o, y_o, m_p, y_p);
		PeakResult pr;
		if (fitpara.oblate) {
			pr = {shape_o, vol_o, 0, 0, coef[4], 0, 0 };
		}
		else {
			pr = { shape_p, vol_p, 0, 0, coef[4], 0, 0 };
		}
		emit sendpara(pr);
		emit sendfit(r);
	}
}

void NPS::hist(int n, int bin) {
	if (n >= 0) {
		int c = counter;
		while (n < mymap[filelist[c]].first || n >= mymap[filelist[c]].second) {
			if (n < mymap[filelist[c]].first)
				c--;
			else
				c++;
			if (c >= filelist.size() || c < 0)
				return;
		}
		if (c != counter) {
			counter = c;
			loaddata();
		}	
		size_t start, end;
		double xmax, xmin;
		gsl_histogram* h = gsl_histogram_alloc(bin);
		QVector<QPointF> r2;
		Peak& peak = siglist[n];
		start = peak.start;
		end = peak.end;
		if (end - start <= 2) {
			QVector<QPointF> r;
			emit sendhistaxis(xmin, xmax, 0, 1);
			emit sendhist(r);
			emit sendcursig(r2);
			emit sendindex(QString::number(n));
			PeakResult pr = { peak.shape, peak.volume, peak.currentbase, peak.currentmax, peak.residues, peak.score, (peak.end - peak.start) * interval / 1000 };
			emit sendpara(pr);
			return;
		}
		xmin = (peak.currentbase - dat.valmin(start, end + 1)) / peak.currentbase;
		xmax = (peak.currentbase - dat.valmax(start, end + 1)) / peak.currentbase;
		if (xmin > xmax)
			std::swap(xmin, xmax);
		gsl_histogram_set_ranges_uniform(h, xmin, xmax);
		for (int i = start; i <= end; i++)
			gsl_histogram_increment(h, (peak.currentbase - dat.at(i)) / peak.currentbase);
		double sum = gsl_histogram_sum(h);
		if (sum > 0.0)
			gsl_histogram_scale(h, 1.0 / (sum * (h->range[1] - h->range[0])));
		r2.push_back(QPointF(start * interval / 1000, peak.currentbase));
		r2.push_back(QPointF(start * interval / 1000, peak.currentmax));
		r2.push_back(QPointF(end * interval / 1000, peak.currentmax));
		r2.push_back(QPointF(end * interval / 1000, peak.currentbase));
		QVector<QPointF> r;
		float maxcount = 0;
		for (int i = 0; i < h->n; i++) {
			maxcount = (h->bin[i] > maxcount) ? h->bin[i] : maxcount;
			r.push_back(QPointF(h->range[i], 0));
			r.push_back(QPointF(h->range[i], h->bin[i]));
			r.push_back(QPointF(h->range[i+1], h->bin[i]));
			r.push_back(QPointF(h->range[i+1], 0));
		}
		emit sendhistaxis(xmin, xmax, 0, maxcount);
		emit sendhist(r);
		emit sendcursig(r2);
		emit sendindex(QString::number(n));
		PeakResult pr = { peak.shape, peak.volume, peak.currentbase, peak.currentmax, peak.residues, peak.score, (peak.end - peak.start) * interval / 1000 };
		emit sendpara(pr);
		gsl_histogram_free(h);
	}
	else {
		std::vector<double> multievent;
		double xmax, xmin;
		size_t start, end;
		for (int i = 0; i < siglist.size(); i++) {
			Peak& peak = siglist[i];
			start = peak.start;
			end = peak.end;
			multievent.push_back((siglist[i].currentbase - siglist[i].currentmax)/ siglist[i].currentbase);
			if (i == 0) {
				xmax = multievent[0];
				xmin = multievent[0];
			}
			else {
				xmax = (xmax < multievent[i]) ? multievent[i] : xmax;
				xmin = (xmin > multievent[i]) ? multievent[i] : xmin;
			}
		}
		gsl_histogram* h = gsl_histogram_alloc(bin);
		gsl_histogram_set_ranges_uniform(h, xmin, xmax);
		for (int i = 0; i < multievent.size(); i++)
			gsl_histogram_increment(h, multievent[i]);
		double sum = gsl_histogram_sum(h);
		if (sum > 0.0)
			gsl_histogram_scale(h, 1.0 / (sum * (h->range[1] - h->range[0])));
		QVector<QPointF> r;
		int maxcount = 0;
		for (int i = 0; i < h->n; i++) {
			maxcount = (h->bin[i] > maxcount) ? h->bin[i] : maxcount;
			r.push_back(QPointF(h->range[i], 0));
			r.push_back(QPointF(h->range[i], h->bin[i]));
			r.push_back(QPointF(h->range[i + 1], h->bin[i]));
			r.push_back(QPointF(h->range[i + 1], 0));
		}
		emit sendhistaxis(xmin, xmax, 0, maxcount);
		emit sendhist(r);
		gsl_histogram_free(h);
	}
	emit sendindex(QString::number(n));
}

void NPS::setBin(int i) {
	if (i <= 0)
		return;
	bin = i;
	hist(index, bin);
}

void NPS::setIndex(int i) {
	if ((i < -1) || (i>=0 && i >= siglist.size()))
		return;
	index = i;
	hist(index, bin);
}

void NPS::pretrace() {
	if (counter <= 0)
		return;
	counter--;
	loaddata();
	index = mymap[filelist[counter]].first;
	hist(index, bin);
}

void NPS::nexttrace() {
	if (counter >= filelist.size() - 1)
		return;
	counter++;
	loaddata();
	index = mymap[filelist[counter]].first;
	hist(index, bin);
	
}

void NPS::prehist() {
	if (index <= -1)
		return;
	index--;
	hist(index, bin);
}

void NPS::nexthist() {
	if (index>=0 && index >= siglist.size() - 1)
		return;
	index++;
	hist(index, bin);
}

void NPS::sethist(float time) {
	if (counter < 0)
		return;
	size_t t = time * 1000 / interval;
	size_t start = mymap[filelist[counter]].first;
	size_t end = mymap[filelist[counter]].second;
	size_t mid;
	while (true) {
		mid = (start + end) / 2;
		if (t >= siglist[mid].start && t <= siglist[mid].end)
			break;
		else if (t < siglist[mid].start)
			end = mid;
		else
			start = mid + 1;
		if (start >= end)
			return;
	}
	index = mid;
	hist(index, bin);
}

void NPS::zoomin() {
	Peak peak = siglist[index];
	size_t start = peak.start;
	size_t end = peak.end;
	float ymin = dat.valmin(start, end + 1);
	float ymax = dat.valmax(start, end + 1);
	emit sendaxis(peak.start * interval / 1000 - 1, peak.end * interval / 1000 + 1, ymin - 500, ymax + 500, false);
	trace(peak.start * interval / 1000 - 2, peak.end * interval / 1000 + 2);
}

void NPS::peakanalysis(int n, double xmin, double xmax) {
	size_t start, end;
	Peak& peak = siglist[n];
	start = peak.start;
	end = peak.end;
	if (peak.currentbase == 0)
		peak.currentbase = dat.baseline(start, end + 1);
	if (peak.currentmax == 0) 
		peak.currentmax = (peak.currentbase > 0) ? xmin : xmax;
	size_t i, j;
	i = (start < end - start) ? 0 : 2 * start - end;
	j = (2 * end - start > dat.size()) ? dat.size() : 2 * end - start;
	double score = 0;
	int num = 0;
	for (int k = i; k < start + 1; k++) {
		score += abs(dat.at(k) - peak.currentbase);
		num++;
	}
	for (int k = end + 1; k < j; k++) {
		score += abs(dat.at(k) - peak.currentbase);
		num++;
	}
	peak.score = score / num;
	return;
}

void NPS::savenps() {
	std::string fnout = ".txt";
	fnout.insert(0, fn, 0, fn.size() - 4);
	std::ofstream file;
	file.open(fnout);
	file << "offset(us) t0(us) dt(ms) baseline(pA) peakcurrent(pA) dImin(pA) dImax(pA) score residues volume shape\n";
	for (int i = 0; i < siglist.size(); i++) {
		std::string buff;
		buff += std::to_string(i*20) + " ";
		buff += std::to_string(siglist[i].start * interval / 1000) + " ";
		buff += std::to_string((siglist[i].end - siglist[i].start) * interval / 1000) + " ";
		buff += std::to_string(siglist[i].currentbase) + " ";
		buff += std::to_string(siglist[i].currentmax) + " ";
		buff += std::to_string(siglist[i].Imin) + " ";
		buff += std::to_string(siglist[i].Imax) + " ";
		buff += std::to_string(siglist[i].score) + " ";
		buff += std::to_string(siglist[i].residues) + " ";
		buff += std::to_string(siglist[i].volume) + " ";
		buff += std::to_string(siglist[i].shape) + "\n";
		file << buff;
	}
	file.close();
	NPSIO nps;
	nps.filelist = filelist;
	nps.siglist = siglist;
	nps.mymap = mymap;
	nps.paralist = paralist;
	nps.n = filelist.size();
	nps.save(fn);
	
	return;
}

void NPS::fitall() {
	emit sendmessage(QString("fitting"));
	for (int i = 0; i < filelist.size(); i++) {
		std::string a = filelist[i];
		interval = paralist[i].interval;
		dat.open(a);
		for (int j = mymap[filelist[i]].first; j < mymap[filelist[i]].second; j++) {
			int progress = ((float)j / (float)siglist.size()) * 100;
			emit sendprocess(progress);
			size_t start, end;
			Peak& peak = siglist[j];
			if ((peak.currentbase - peak.currentmax) / peak.currentbase < fitpara.ileft || (peak.currentbase - peak.currentmax) / peak.currentbase > fitpara.iright)
				continue;
			start = peak.start;
			end = peak.end;
			if (((end - start) * interval < fitpara.dt0) || ((end - start) * interval > fitpara.dt1))
				continue;
			mwArray mdata(1, end - start + 1, mxDOUBLE_CLASS, mxREAL);
			double* data = new double[end - start + 1];
			for (int i = 0; i < end - start + 1; i++) {
				data[i] = (peak.currentbase - dat.at(i + start)) / peak.currentbase * 10000;
			}
			mdata.SetData(data, end - start + 1);
			mwArray margs(1, 9, mxDOUBLE_CLASS);
			double args[9] = { Efield(physical), fitpara.noise0, fitpara.noise1, fitpara.noise2, fitpara.dipole0,fitpara.dipole1,fitpara.dipole2,fitpara.imin, fitpara.imax };
			margs.SetData(args, 9);
			mwArray mcoef;
			mwArray mdatax;
			mwArray mdatay;
			IntraEventFit(3, mdatax, mdatay, mcoef, mdata, margs);
			double datax[40];
			mdatax.GetData(datax, 40);
			double datay[40];
			mdatay.GetData(datay, 40);
			double coef[5];
			mcoef.GetData(coef, 5);
			QVector<QPointF> r;
			for (int i = 0; i < 40; i++) {
				r.push_back(QPointF(datax[i], datay[i]));
			}
			peak.Imin = coef[0];
			peak.Imax = coef[1];
			peak.residues = coef[4];
			float shape_o, shape_p, vol_o, vol_p;
			float g = gvalue(physical);
			if (m_o.empty()) {
				m_o = std::vector<float>(999);
				m_p = std::vector<float>(999);
				y_o = std::vector<float>(999);
				y_p = std::vector<float>(999);
				oblate(m_o, y_o);
				prolate(m_p, y_p);
			}
			volum_shape(shape_o, vol_o, shape_p, vol_p, peak.Imin, peak.Imax, g, m_o, y_o, m_p, y_p);
			if (fitpara.oblate) {
				peak.shape = shape_o;
				peak.volume = vol_o;
			}
			else {
				peak.shape = shape_p;
				peak.volume = vol_p;
			}
			delete[] data;
		}
	}
	emit sendprocess(100);
	emit sendmessage(QString(" "));
	loaddata();
}

void NPS::anall() {
	if (fn.substr(fn.size() - 3, 3) == std::string("nps"))
		return;
	for (int i = 0; i < filelist.size(); i++) {
		std::string a = filelist[i];
		interval = paralist[i].interval;
		dat.open(a);
		for (int j = mymap[filelist[i]].first; j < mymap[filelist[i]].second; j++) {
			int progress = ((float)j / (float)siglist.size()) * 100;
			emit sendprocess(progress);
			size_t start, end;
			double xmax, xmin;
			Peak& peak = siglist[j];
			start = peak.start;
			end = peak.end;
			xmin = dat.valmin(start, end + 1);
			xmax = dat.valmax(start, end + 1);
			peakanalysis(j, xmin, xmax);
		}
	}
	emit sendprocess(100);
}
void NPS::setpara(Physical p, FitPara fp) {
	physical = p;
	fitpara = fp;
}

void NPS::median() {
	std::vector<float> shapelist;
	std::vector<float> volumelist;
	for (int i = 0; i < siglist.size(); i++) {
		if (siglist[i].shape != 0) {
			shapelist.push_back(siglist[i].shape);
			volumelist.push_back(siglist[i].volume);
		}
	}
	std::sort(shapelist.begin(), shapelist.end());
	std::sort(volumelist.begin(), volumelist.end());
	emit sendmedian(shapelist[shapelist.size() / 2], volumelist[volumelist.size() / 2]);
}