#ifndef AUTOWIDGET_H
#define AUTOWIDGET_H

#include <QtWidgets/QRubberBand>
#include <QtWidgets/QWidget>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlineedit.h>
#include <QtCore/qthread.h>
#include <QtCharts/qsplineseries.h>
#include <QtCharts/qscatterseries.h>
#include <QtCharts/qvalueaxis.h>
#include "automodel.h"


class AUTOWidget :public QWidget {
	Q_OBJECT;
public:
	AUTOWidget();
	~AUTOWidget();
	void init(QStringList);
public slots:
	void runpf();
signals:
	void sendpf(float, float, float, float, QString);
	void sendfn(std::vector<std::string>);
private:
	QThread* thread;
};

#endif // !AUTOWIDGET_H
