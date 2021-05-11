#ifndef DATMODEL_H
#define DATMODEL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <QtCore/qobject.h>
#include <QtCore/qvector.h>
#include <gsl/gsl_vector.h>
#include "datio.h"
#include "tools.h"

class DATModel:public QObject {
	Q_OBJECT
public: ~DATModel();
public slots:
	void load(std::string);
	void signal(float sigma, float freq, float thres);
	void save(QVector<QPointF>);
	void draw(double xmin, double xmax);
	void savenps(float, float, float, float);
	void home();
	void removenps();
	void lowpass(float, float);
	void setinterval(float);

signals:
	void sendData(QVector<QPointF>);
	void sendAxis(float xmin, float xmax, float ymin, float ymax);
	void sendData_f(QVector<QPointF>, float, float);
	void sendProcess(int);

private:
	DATIO dat;
	std::string fn;
	float interval;
	std::vector<Peak> sigs;
	size_t n;
	std::vector<float> data_smooth;
};



#endif //DATMODEL_H