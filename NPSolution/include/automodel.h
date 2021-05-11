#ifndef AUTOMODEL_H
#define AUTOMODEL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <QtCore/qobject.h>
#include <QtCore/qvector.h>
#include <gsl/gsl_vector.h>
#include "datio.h"
#include "tools.h"

class AUTOModel :public QObject {
	Q_OBJECT
public: ~AUTOModel();
public slots:
	void load(std::vector<std::string>);
	void signal(float sigma, float freq, float thres, float, QString);
	void setindex(int);
	void draw(float xmin, float xmax);
	void home();
	void remove();
	void nexttrace();
	void pretrace();

signals:
	void sendAxis(float xmin, float xmax, float ymin, float ymax, bool);
	void sendData(QVector<QPointF>);
	void sendProcess(int);
	void sendPath(QString);
	void sendIndex(const QString&);
	void sendNum(const QString&);
	void sendDev(double);
	void sendBaseline(double);

private:
	DATIO dat;
	std::vector<std::string> fn;
	float interval = 2;
	std::vector<Peak> sigs;
	Para para;
	size_t n;
	size_t index = 0;
	std::vector<float> data_smooth;
};



#endif // !AUTOMODEL_H
