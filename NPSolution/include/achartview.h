#ifndef ACHARTVIEW_H
#define ACHARTVIEW_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtCharts/qsplineseries.h>
#include <QtCharts/qscatterseries.h>
#include <QtCharts/qvalueaxis.h>
#include "datmodel.h"

QT_CHARTS_USE_NAMESPACE

class AChartView : public QChartView
{
    Q_OBJECT;
public:
    AChartView(QWidget* parent);
    ~AChartView();
    void open(QString fn);

public slots:
    //void setFilename(QString s);
    void changex1();
    void changex2();
    void changey2();
    void changey1();
    void back();
    void home();
    void initui(float x1, float x2, float y1, float y2);
    void additem();
    void delitem();
    void save();
    void savesig();
    void startprocess();
    void update_d(QVector<QPointF>);
    void update_f(QVector<QPointF>, float, float);
    void currentprocess(int);
    void startsmooth();
    void setinterval();

signals:
    void settime(double num);
    void getdata(double s, double e);
    void loadprocess(float sigma, float freq, float thres);
    void sendsave(QVector<QPointF>);
    void setsignum(QString);
    void setprocess(int);
    void setmean(QString);
    void setSD(QString);
    void nps(float, float, float, float);
    void smooth(float, float);
    void removenps();
    void setcurrent(double);
    void gethome();
    void sendinterval(float);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    QLineSeries* series;
    QLineSeries* series_f;
    QChart* charts;
    QValueAxis* axisx;
    QValueAxis* axisy;
    QRubberBand* rubberBand = NULL;
    DATModel* datmodel = NULL;
    QThread* thread = NULL;
    std::vector<QPair<double, double>> stx;
    std::vector<QPair<double, double>> sty;
    double start = 0;
    double end = 0;
    bool iostatus = false;
    bool modelflag = false;
    
};
#endif //ACHARTVIEW_H 