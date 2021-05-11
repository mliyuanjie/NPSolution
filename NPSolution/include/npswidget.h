#ifndef NPSWIDGET_H
#define NPSWIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/qpushbutton.h>
#include <QtCore/qthread.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qspinbox.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qprogressbar.h>
#include "nps.h"
#include "fitset.h"


class NPSWidget : public QWidget {
	Q_OBJECT;
public:
	NPSWidget(QWidget* parent);
	~NPSWidget();
	void open(QString);

public slots: 
	void setting();
	void setpara();
	void setmedian(float, float);


signals:
	void start();
	void sendpara(Physical, FitPara);
private:
	QThread* thread;
	QWidget* popUp;
};

#endif // !NPSWIDGET_H

