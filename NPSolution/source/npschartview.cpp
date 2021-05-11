#include "npschartview.h"

NPSChartView::NPSChartView(QWidget* parent) :
    QtCharts::QChartView(parent) 
{
    axisx = new QValueAxis();
    axisx->setGridLineVisible(false);
    axisy = new QValueAxis();
    axisy->setGridLineVisible(false);
    axisx->setTitleText(QString("Time(ms)"));
    axisy->setTitleText(QString("Current(pA)"));
    series_d = new QLineSeries();
    series_f = new QLineSeries();
    series_p = new QLineSeries();
    series_d->setPen(QPen(Qt::darkBlue, 2));
    series_f->setPen(QPen(Qt::green, 2, Qt::DashDotDotLine));
    series_p->setPen(QPen(Qt::red, 2));
    //series->setUseOpenGL(true);
    charts = new QChart();
    charts->addSeries(series_d);
    charts->addSeries(series_f);
    charts->addSeries(series_p);
    charts->setAxisX(axisx, series_d);
    charts->setAxisY(axisy, series_d);
    charts->setAxisX(axisx, series_f);
    charts->setAxisY(axisy, series_f);
    charts->setAxisX(axisx, series_p);
    charts->setAxisY(axisy, series_p);
    charts->legend()->hide();
    setChart(charts);
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
}

void NPSChartView::mousePressEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    rubberBand->setGeometry(QRect(p, QSize()));
    rubberBand->show();        
}

void NPSChartView::mouseMoveEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    rubberBand->setGeometry(QRect(rubberBand->pos(), event->pos()));
    emit sendyaxis(pf.y());
}

void NPSChartView::mouseReleaseEvent(QMouseEvent* event) {
    QPoint p = event->pos();
    QPointF pf = mapToScene(p);
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    QPair<float, float> x;
    QPair<float, float> y;
    x.second = pf.x();
    y.first = pf.y();
    pf = mapToScene(rubberBand->pos());
    pf = charts->mapFromScene(pf);
    pf = charts->mapToValue(pf);
    x.first = pf.x();
    y.second = pf.y();
    if (event->button() == Qt::LeftButton) 
        emit sendxaxis(x.second - x.first);
    else if (event->button() == Qt::RightButton) {
        stx.push_back(x);
        sty.push_back(y);
        emit gettrace(stx.back().first, stx.back().second);
        rubberBand->hide();
        axisx->setRange(stx.back().first, stx.back().second);
        axisy->setRange(sty.back().first, sty.back().second);
    }
    rubberBand->hide();
}

void NPSChartView::mouseDoubleClickEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QPoint p = event->pos();
        QPointF pf = mapToScene(p);
        pf = charts->mapFromScene(pf);
        pf = charts->mapToValue(pf);
        emit gethist(pf.x());
    }
}

void NPSChartView::back() {
    if (stx.size() <= 1)
        return;
    stx.pop_back();
    sty.pop_back();
    axisx->setRange(stx.back().first, stx.back().second);
    axisy->setRange(sty.back().first, sty.back().second);
    emit gettrace(stx.back().first, stx.back().second);
}

void NPSChartView::home() {
    while (stx.size() > 1) {
        stx.pop_back();
        sty.pop_back();
    }
    axisx->setRange(stx.back().first, stx.back().second);
    axisy->setRange(sty.back().first, sty.back().second);
    emit gettrace(stx.back().first, stx.back().second);
}

void NPSChartView::initaxis(float x1, float x2, float y1, float y2, bool init) {
    if (init) {
        stx.clear();
        sty.clear();
    }
    stx.push_back(QPair<float, float>(x1, x2));
    sty.push_back(QPair<float, float>(y1, y2));
    axisx->setRange(x1, x2);
    axisy->setRange(y1, y2);
}

void NPSChartView::update_d(QVector<QPointF> data) {
    series_d->replace(data);
}

void NPSChartView::update_f(QVector<QPointF> data) {
    series_f->replace(data);
}

void NPSChartView::update_p(QVector<QPointF> data) {
    series_p->replace(data);
}