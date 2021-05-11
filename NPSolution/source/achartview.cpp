#include <QtGui/QMouseEvent>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QtMath>
#include <QtCore/qdebug.h>
#include <QtCore/qthread.h>
#include <QtCore/qmetatype.h>
#include "achartview.h"

AChartView::AChartView(QWidget* parent) :
    QChartView(parent)
{
    axisx = new QValueAxis();
    axisx->setGridLineVisible(false);
    axisy = new QValueAxis();
    axisy->setGridLineVisible(false);
    series = new QLineSeries();
    series_f = new QLineSeries();
    series->setPen(QPen(Qt::darkBlue, 2)); 
    series_f->setPen(QPen(Qt::darkGreen, 2));
    //series->setUseOpenGL(true);
    charts = new QtCharts::QChart();
    charts->addSeries(series);
    charts->addSeries(series_f);
    charts->setAxisX(axisx, series);
    charts->setAxisY(axisy, series);
    charts->setAxisX(axisx, series_f);
    charts->setAxisY(axisy, series_f);
    charts->legend()->hide();
    setChart(charts);
    qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
}

AChartView::~AChartView() {
    thread->quit();
}

void AChartView::mousePressEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    start = pf.x();
    rubberBand->setGeometry(QRect(p, QSize()));
    rubberBand->show();
}

void AChartView::mouseMoveEvent(QMouseEvent* event) {
    rubberBand->setGeometry(QRect(rubberBand->pos(), event->pos()));   
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    emit setcurrent(pf.y());
}

void AChartView::mouseReleaseEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    end = pf.x();
    emit settime(end - start);
    if (event->button() == Qt::RightButton) {
        QPair<double, double> x;
        QPair<double, double> y;
        x.second = pf.x();
        y.first = pf.y();
        pf = mapToScene(rubberBand->pos());
        pf = charts->mapFromScene(pf);
        pf = charts->mapToValue(pf);
        x.first = pf.x();
        y.second = pf.y();
        stx.push_back(x);
        sty.push_back(y);
        emit getdata(stx.back().first, stx.back().second);
        axisx->setRange(stx.back().first, stx.back().second);
        axisy->setRange(sty.back().first, sty.back().second);
    }
    rubberBand->hide();
}

void AChartView::back() {
    if (stx.size() <= 1)
        return;
    stx.pop_back();
    sty.pop_back();
    axisx->setRange(stx.back().first, stx.back().second);
    axisy->setRange(sty.back().first, sty.back().second);
    getdata(stx.back().first, stx.back().second);
}

void AChartView::home() {
    emit gethome();
}

void AChartView::changex1() {
    float range = stx.back().second - stx.back().first;
    stx.back().first = stx.back().first - 0.2 * range;
    stx.back().second = stx.back().second + 0.2 * range;
    axisx->setRange(stx.back().first, stx.back().second);
    emit getdata(stx.back().first, stx.back().second);
}

void AChartView::changex2() {
    float range = stx.back().second - stx.back().first;
    stx.back().first = stx.back().first + 0.2 * range;
    stx.back().second = stx.back().second - 0.2 * range;
    axisx->setRange(stx.back().first, stx.back().second);
    emit getdata(stx.back().first, stx.back().second);
}

void AChartView::changey1() {
    float range = sty.back().second - sty.back().first;
    sty.back().first = sty.back().first - 0.2 * range;
    sty.back().second = sty.back().second + 0.2 * range;
    axisy->setRange(sty.back().first, sty.back().second);
}

void AChartView::changey2() {
    float range = sty.back().second - sty.back().first;
    sty.back().first = sty.back().first + 0.2 * range;
    sty.back().second = sty.back().second - 0.2 * range;
    axisy->setRange(sty.back().first, sty.back().second);
}

void AChartView::additem() {
    QTableWidget* pt = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QTableWidget*>("tableWidget");
    int index = pt->rowCount();
    pt->insertRow(index);
    pt->setItem(index, 0, new QTableWidgetItem(QString::number(start)));
    pt->setItem(index, 1, new QTableWidgetItem(QString::number(end)));
    index++;  
}

void AChartView::delitem() {
    QTableWidget* pt = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QTableWidget*>("tableWidget");
    int index = pt->rowCount();
    pt->removeRow(index-1);
}

void AChartView::update_d(QVector<QPointF> data) {
    series->replace(data);
    return;
}

void AChartView::update_f(QVector<QPointF> data, float mean, float sd) {
    emit setsignum(QString().setNum(data.size() / 4));
    emit setmean(QString().setNum(mean));
    emit setSD(QString().setNum(sd));
    series_f->replace(data);
    this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QPushButton*>("pushButton_12")->setVisible(true);
    return;
}

void AChartView::initui(float x1, float x2, float y1, float y2) {
    axisx->setTitleText(QString("Time(ms)"));
    axisy->setTitleText(QString("Current(pA)"));
    stx.clear();
    sty.clear();
    stx.push_back(QPair<float, float>(x1, x2));
    sty.push_back(QPair<float, float>(y1, y2));
    axisx->setRange(x1, x2);
    axisy->setRange(y1, y2);
    emit getdata(x1, x2);
}

void AChartView::open(QString fn) {
    if (modelflag) {
        iostatus = false;
        this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QPushButton*>("pushButton_12")->setText("save");
        datmodel->load(fn.toStdString());
        return;
    }
    thread = new QThread(this);
    datmodel = new DATModel();
    datmodel->moveToThread(thread);
    connect(thread, SIGNAL(finished()), datmodel, SLOT(deleteLater()));
    connect(this, SIGNAL(getdata(double, double)), datmodel, SLOT(draw(double, double)));
    connect(datmodel, SIGNAL(sendAxis(float, float, float, float)), this, SLOT(initui(float, float, float, float)));
    connect(datmodel, SIGNAL(sendData(QVector<QPointF>)), this, SLOT(update_d(QVector<QPointF>)));
    connect(this, SIGNAL(loadprocess(float, float, float)), datmodel, SLOT(signal(float, float, float)));
    connect(this, SIGNAL(smooth(float, float)), datmodel, SLOT(lowpass(float, float)));
    connect(this, SIGNAL(sendinterval(float)), datmodel, SLOT(setinterval(float)));
    connect(datmodel, SIGNAL(sendData_f(QVector<QPointF>, float, float)), this, SLOT(update_f(QVector<QPointF>, float, float)));
    connect(this, SIGNAL(sendsave(QVector<QPointF>)), datmodel, SLOT(save(QVector<QPointF>)));
    connect(datmodel, SIGNAL(sendProcess(int)), this, SLOT(currentprocess(int)));
    connect(this, SIGNAL(nps(float, float, float, float)), datmodel, SLOT(savenps(float, float, float, float)));
    connect(this, SIGNAL(removenps()), datmodel, SLOT(removenps()));
    connect(this, SIGNAL(gethome()), datmodel, SLOT(home()));
    thread->start();
    datmodel->load(fn.toStdString());
    modelflag = true;
}

void AChartView::save() {
    QTableWidget* pt = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QTableWidget*>("tableWidget");
    QVector<QPointF> range;
    for (int i = 0; i < pt->rowCount(); i++) {
        range.push_back(QPointF(pt->item(i, 0)->text().toFloat(), pt->item(i, 1)->text().toFloat()));
    }
    emit sendsave(range);
    pt->clear();
    pt->removeRow(0);
}

void AChartView::startprocess() {
    QLineEdit* pt_sigma = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLineEdit*>("lineEdit");
    QLineEdit* pt_freq = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLineEdit*>("lineEdit_2");
    QLineEdit* pt_thres = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLineEdit*>("lineEdit_3");
    emit  loadprocess(pt_sigma->text().toFloat(), pt_freq->text().toFloat(), pt_thres->text().toFloat());
}

void AChartView::startsmooth() {
    QLineEdit* pt_sigma = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLineEdit*>("lineEdit");
    QLineEdit* pt_freq = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLineEdit*>("lineEdit_2");
    emit  smooth(pt_sigma->text().toFloat(), pt_freq->text().toFloat());
}

void AChartView::currentprocess(int a) {
    emit setprocess(a);
}

void AChartView::savesig() {
    if (iostatus) {
        iostatus = false;
        this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QPushButton*>("pushButton_12")->setText("save");
        emit removenps();
    }
    else {
        QLineEdit* pt_sigma = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLineEdit*>("lineEdit");
        QLineEdit* pt_freq = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLineEdit*>("lineEdit_2");
        QLineEdit* pt_thres = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLineEdit*>("lineEdit_3");
        QLabel* pt_sd = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLabel*>("label_17");
        emit nps(pt_sigma->text().toFloat(), pt_freq->text().toFloat(), pt_thres->text().toFloat(), pt_sd->text().toFloat());
        this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QPushButton*>("pushButton_12")->setText("remove");
        iostatus = true;
    }
}

void AChartView::setinterval() {
    QLineEdit* pt = this->parent()->findChild<QTabWidget*>("tabWidget")->findChild<QWidget*>("tab_2")->findChild<QLineEdit*>("lineEdit_4");
    emit sendinterval(pt->text().toFloat());
}