#include "histchartview.h" 


HistChartView::HistChartView(NPSWidget* parent) :
    QChartView(parent) {
    axisx = new QValueAxis();
    axisx->setGridLineVisible(false);
    axisy = new QValueAxis();
    axisy->setGridLineVisible(false);
    axisx->setLabelFormat("%.2f");
    axisx->setTitleText(QString("dI/I0"));
    axisy->setTitleText(QString("Count"));
    series = new QLineSeries();
    series->setPen(QPen(Qt::black, 3));
    series_f = new QLineSeries();
    series_f->setPen(QPen(Qt::red, 2));
    charts = new QChart();
    charts->addSeries(series);
    charts->addSeries(series_f);
    charts->setAxisX(axisx, series);
    charts->setAxisY(axisy, series);
    charts->setAxisX(axisx, series_f);
    charts->setAxisY(axisy, series_f);
    charts->legend()->hide();
    setChart(charts);
}

void HistChartView::mouseDoubleClickEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) 
        emit zoomin();
}

void HistChartView::initaxis(float x1, float x2, float y1, float y2) {
    axisx->setRange(x1, x2);
    axisy->setRange(y1, y2);
}

void HistChartView::update(QVector<QPointF> data) {
    series->replace(data);
}

void HistChartView::update_d(QVector<QPointF> data) {
    series_f->replace(data);
}

void HistChartView::setindex() {
    QString s = this->parent()->findChild<QLineEdit*>("lineEdit_7")->text();
    emit indexedited(s.toInt());
}

void HistChartView::setbin() {
    QString s = this->parent()->findChild<QLineEdit*>("lineEdit_8")->text();
    emit binedited(s.toInt());
}