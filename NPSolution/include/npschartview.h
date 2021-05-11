#ifndef NPSCHARTVIEW_H
#define NPSCHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtCharts/qvalueaxis.h>
#include <QtCharts/qsplineseries.h>
#include "npswidget.h"

QT_CHARTS_USE_NAMESPACE

class NPSChartView : public QChartView
{
    Q_OBJECT;
public:
    NPSChartView(QWidget* parent);

public slots:
    //void setFilename(QString s);
    void initaxis(float, float, float, float, bool);
    void update_d(QVector<QPointF>);
    void update_f(QVector<QPointF>);
    void update_p(QVector<QPointF>);
    void back();
    void home();

signals:
    void gettrace(float, float);
    void gethist(float);
    void sendyaxis(double);
    void sendxaxis(double);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    QLineSeries* series_d;
    QLineSeries* series_f;
    QLineSeries* series_p;
    QValueAxis* axisx;
    QValueAxis* axisy;
    QChart* charts;
    QRubberBand* rubberBand = NULL;
    std::vector<QPair<float, float>> stx;
    std::vector<QPair<float, float>> sty;
    double start = 0;
    double end = 0;
};
#endif // !NPSCHARTVIEW_H

