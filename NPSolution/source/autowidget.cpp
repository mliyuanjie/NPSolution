#include <QtWidgets/QFileDialog>
#include "npschartview.h"
#include "autowidget.h" 


AUTOWidget::AUTOWidget() :
	QWidget() {
	thread = new QThread();
	qRegisterMetaType<std::vector<std::string>>("std::vector<std::string>");
	qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
}
AUTOWidget::~AUTOWidget() {
	thread->quit();
	thread = NULL;
}
void AUTOWidget::init(QStringList qfiles) {
    std::vector<std::string> files;
    for (int i = 0; i < qfiles.size(); i++) {
        files.push_back(qfiles.at(i).toStdString());
    }
    AUTOModel* model = new AUTOModel();
    model->moveToThread(thread);
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	connect(thread, SIGNAL(finished()), model, SLOT(deleteLater()));
	connect(this->findChild<QPushButton*>("pushButton_2"), SIGNAL(clicked()), model, SLOT(nexttrace()));
	connect(this->findChild<QPushButton*>("pushButton"), SIGNAL(clicked()), model, SLOT(pretrace()));
	connect(this->findChild<QPushButton*>("pushButton_10"), SIGNAL(clicked()), model, SLOT(remove()));
	connect(this, SIGNAL(sendfn(std::vector<std::string>)), model, SLOT(load(std::vector<std::string>)));
	connect(model, SIGNAL(sendIndex(const QString&)), this->findChild<QLineEdit*>("lineEdit_5"), SLOT(setText(const QString&)));
	connect(model, SIGNAL(sendNum(const QString&)), this->findChild<QLabel*>("label_2"), SLOT(setText(const QString&)));
	connect(model, SIGNAL(sendBaseline(double)), this->findChild<QLabel*>("label_4"), SLOT(setNum(double)));
	connect(model, SIGNAL(sendDev(double)), this->findChild<QLabel*>("label_3"), SLOT(setNum(double)));
	connect(model, SIGNAL(sendData(QVector<QPointF>)), this->findChild<NPSChartView*>("graphicsView"), SLOT(update_d(QVector<QPointF>)));
	connect(model, SIGNAL(sendAxis(float, float, float, float, bool)), this->findChild<NPSChartView*>("graphicsView"), SLOT(initaxis(float, float, float, float, bool)));
	connect(this->findChild<QPushButton*>("pushButton_13"), SIGNAL(clicked()), this, SLOT(runpf()));
	connect(this, SIGNAL(sendpf(float, float, float, float, QString)), model, SLOT(signal(float, float, float, float, QString)));
	connect(this->findChild<NPSChartView*>("graphicsView"), SIGNAL(gettrace(float, float)), model, SLOT(draw(float, float)));
	connect(model, SIGNAL(sendPath(const QString&)), this->findChild<QLabel*>("label"), SLOT(setText(const QString&)));
	connect(model, SIGNAL(sendProcess(int)), this->findChild<QProgressBar*>("progressBar"), SLOT(setValue(int)));
	thread->start();
	emit sendfn(files);
}

void AUTOWidget::runpf() {
	float sigma = this->findChild<QLineEdit*>("lineEdit")->text().toFloat();
	float freq = this->findChild<QLineEdit*>("lineEdit_2")->text().toFloat();
	float thres = this->findChild<QLineEdit*>("lineEdit_3")->text().toFloat();
	float inter = this->findChild<QLineEdit*>("lineEdit_4")->text().toFloat();
	QString fn = this->findChild<QLineEdit*>("lineEdit_6")->text()+QString(".nps");
	emit sendpf(sigma, freq, thres, inter, fn);
}