#ifndef QPARABOX_H
#define QPARBOX_H


#include <QtWidgets/QGroupBox>
#include <QtWidgets/qlabel.h>

struct PeakResult {
    double Imin;
    double Imax;
    double baseline;
    double Imean;
    double residues;
    double quality;
    double dt;
};
class QParaBox : public QGroupBox
{
    Q_OBJECT;
public:
    QParaBox(QWidget* parent);

public slots:
    void setpara(PeakResult);
};
#endif //QPARABOX_H
