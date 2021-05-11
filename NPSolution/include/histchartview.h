#ifndef HISTCHARTVIEW_H
#define HISTCHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtCharts/qsplineseries.h>
#include <QtCharts/qscatterseries.h>
#include <QtCharts/qvalueaxis.h>
#include "npswidget.h"

QT_CHARTS_USE_NAMESPACE

class HistChartView : public QChartView
{
    Q_OBJECT;
public:
    HistChartView(NPSWidget* parent);

public slots:
    //void setFilename(QString s);
    void initaxis(float, float, float, float);
    void update(QVector<QPointF>);
    void update_d(QVector<QPointF>);
    void setindex();
    void setbin();

signals:
    void indexedited(int);
    void binedited(int);
    void zoomin();

protected:
    void HistChartView::mouseDoubleClickEvent(QMouseEvent* event);

private:
    QLineSeries* series;
    QLineSeries* series_f;
    QChart* charts;
    QValueAxis* axisx;
    QValueAxis* axisy;
};
#endif // !HISTCHARTVIEW_H
