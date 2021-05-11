#include "qparabox.h"

QParaBox::QParaBox(QWidget* parent) : QGroupBox(parent) {}

void QParaBox::setpara(PeakResult r) {
	this->findChild<QLabel*>("label_33")->setNum(r.Imin);
	this->findChild<QLabel*>("label_35")->setNum(r.Imax);
	this->findChild<QLabel*>("label_31")->setNum(r.residues);
	this->findChild<QLabel*>("label_27")->setNum(r.dt);
	this->findChild<QLabel*>("label_26")->setNum(r.baseline);
	this->findChild<QLabel*>("label_37")->setNum(r.Imean);
	this->findChild<QLabel*>("label_39")->setNum(r.quality);
}