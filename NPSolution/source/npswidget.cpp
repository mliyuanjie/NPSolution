#include "npschartview.h"
#include "histchartview.h"
#include "qparabox.h"
#include "npswidget.h"


NPSWidget::NPSWidget(QWidget* parent) :
	QWidget(parent) {
	qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
	qRegisterMetaType<PeakResult>("PeakResult");
	qRegisterMetaType<Physical>("Physical");
	qRegisterMetaType<FitPara>("FitPara");
	thread = new QThread();
	Ui::Fitting ui;
	popUp = new QWidget(this, Qt::Popup | Qt::Dialog);
	popUp->setWindowModality(Qt::WindowModal);
	ui.setupUi(popUp);
}

NPSWidget::~NPSWidget() {
	thread->quit();
	thread = NULL;
}

void NPSWidget::open(QString filename) {
	NPS* nps = new NPS();
	nps->moveToThread(thread);
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	connect(thread, SIGNAL(finished()), nps, SLOT(deleteLater()));
	connect(this->findChild<QPushButton*>("pushButton_6"), SIGNAL(clicked()), nps, SLOT(nexttrace()));
	connect(this->findChild<QPushButton*>("pushButton_8"), SIGNAL(clicked()), nps, SLOT(pretrace()));
	connect(this->findChild<QPushButton*>("pushButton_3"), SIGNAL(clicked()), nps, SLOT(prehist()));
	connect(this->findChild<QPushButton*>("pushButton_4"), SIGNAL(clicked()), nps, SLOT(nexthist()));
	connect(nps, SIGNAL(sendindex(const QString&)), this->findChild<QLineEdit*>("lineEdit_7"), SLOT(setText(const QString&)));
	connect(nps, SIGNAL(sendmessage(const QString&)), this->findChild<QLabel*>("label_5"), SLOT(setText(const QString&)));
	connect(nps, SIGNAL(sendDev(double)), this->findChild<QLabel*>("label_13"), SLOT(setNum(double)));
	connect(this->findChild<HistChartView*>("graphicsView_2"), SIGNAL(indexedited(int)), nps, SLOT(setIndex(int)));
	connect(this->findChild<HistChartView*>("graphicsView_2"), SIGNAL(binedited(int)), nps, SLOT(setBin(int)));
	connect(this->findChild<HistChartView*>("graphicsView_2"), SIGNAL(zoomin()), nps, SLOT(zoomin()));
	connect(nps, SIGNAL(sendtrace(QVector<QPointF>)), this->findChild<NPSChartView*>("graphicsView"), SLOT(update_d(QVector<QPointF>)));
	connect(nps, SIGNAL(sendsig(QVector<QPointF>)), this->findChild<NPSChartView*>("graphicsView"), SLOT(update_f(QVector<QPointF>)));
	connect(nps, SIGNAL(sendcursig(QVector<QPointF>)), this->findChild<NPSChartView*>("graphicsView"), SLOT(update_p(QVector<QPointF>)));
	connect(nps, SIGNAL(sendaxis(float, float, float, float, bool)), this->findChild<NPSChartView*>("graphicsView"), SLOT(initaxis(float, float, float, float, bool)));
	connect(nps, SIGNAL(sendhistaxis(float, float, float, float)), this->findChild<HistChartView*>("graphicsView_2"), SLOT(initaxis(float, float, float, float)));
	connect(nps, SIGNAL(sendhist(QVector<QPointF>)), this->findChild<HistChartView*>("graphicsView_2"), SLOT(update(QVector<QPointF>)));
	connect(nps, SIGNAL(sendfit(QVector<QPointF>)), this->findChild<HistChartView*>("graphicsView_2"), SLOT(update_d(QVector<QPointF>)));
	connect(nps, SIGNAL(sendtracenum(int)), this->findChild<QLabel*>("label_8"), SLOT(setNum(int)));
	connect(nps, SIGNAL(sendsignum(int)), this->findChild<QLabel*>("label_7"), SLOT(setNum(int)));
	connect(nps, SIGNAL(sendtracecur(int)), this->findChild<QLabel*>("label_6"), SLOT(setNum(int)));
	connect(this->findChild<NPSChartView*>("graphicsView"), SIGNAL(gettrace(float, float)), nps, SLOT(trace(float, float)));
	connect(this->findChild<NPSChartView*>("graphicsView"), SIGNAL(gethist(float)), nps, SLOT(sethist(float)));
	connect(this->findChild<QPushButton*>("pushButton_5"), SIGNAL(clicked()), nps, SLOT(fit()));
	connect(this->findChild<QPushButton*>("pushButton_11"), SIGNAL(clicked()), nps, SLOT(savenps()));
	connect(this->findChild<QPushButton*>("pushButton_9"), SIGNAL(clicked()), nps, SLOT(fitall()));
	connect(nps, SIGNAL(sendpara(PeakResult)), this->findChild<QParaBox*>("groupBox"), SLOT(setpara(PeakResult)));
	connect(nps, SIGNAL(sendmedian(float, float)), this, SLOT(setmedian(float, float)));
	connect(nps, SIGNAL(sendprocess(int)), this->findChild<QProgressBar*>("progressBar"), SLOT(setValue(int)));
	connect(this, SIGNAL(start()), nps, SLOT(initui()));
	connect(this, SIGNAL(sendpara(Physical, FitPara)), nps, SLOT(setpara(Physical, FitPara)));
	connect(this->findChild<QPushButton*>("pushButton_10"), SIGNAL(clicked()), nps, SLOT(median()));
	connect(popUp->findChild<QPushButton*>("pushButton"), SIGNAL(clicked()), this, SLOT(setpara()));
	thread->start();
	nps->load(filename.toStdString());
	emit start();
}

void NPSWidget::setting() {
	popUp->show();
}

void NPSWidget::setpara() {
	Physical p;
	p.er = popUp->findChild<QLineEdit*>("lineEdit_3")->text().toFloat();
	p.lp = popUp->findChild<QLineEdit*>("lineEdit_2")->text().toFloat() * 1e-9;
	p.rp = popUp->findChild<QLineEdit*>("lineEdit")->text().toFloat() * 1e-9;
	p.vol = popUp->findChild<QLineEdit*>("lineEdit_4")->text().toFloat();
	FitPara fp;
	fp.oblate = popUp->findChild<QRadioButton*>("radioButton")->isChecked();
	fp.noise0 = popUp->findChild<QLineEdit*>("lineEdit_9")->text().toFloat();
	fp.noise1 = popUp->findChild<QLineEdit*>("lineEdit_11")->text().toFloat();
	fp.noise2 = popUp->findChild<QLineEdit*>("lineEdit_10")->text().toFloat();
	fp.dipole0 = popUp->findChild<QLineEdit*>("lineEdit_12")->text().toFloat();
	fp.dipole1 = popUp->findChild<QLineEdit*>("lineEdit_14")->text().toFloat();
	fp.dipole2 = popUp->findChild<QLineEdit*>("lineEdit_13")->text().toFloat();
	fp.imin = popUp->findChild<QSpinBox*>("spinBox")->value();
	fp.imax = popUp->findChild<QSpinBox*>("spinBox_2")->value();
	fp.ileft = popUp->findChild<QLineEdit*>("lineEdit_15")->text().toFloat();
	fp.iright = popUp->findChild<QLineEdit*>("lineEdit_18")->text().toFloat();
	fp.dt0 = popUp->findChild<QLineEdit*>("lineEdit_8")->text().toFloat();
	fp.dt1 = popUp->findChild<QLineEdit*>("lineEdit_16")->text().toFloat();
	fp.mint = popUp->findChild<QLineEdit*>("lineEdit_17")->text().toFloat();
	emit sendpara(p, fp);
	return;
}

void NPSWidget::setmedian(float a, float b) {
	this->findChild<QLabel*>("label_47")->setNum(a);
	this->findChild<QLabel*>("label_49")->setNum(b);
}
