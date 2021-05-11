/********************************************************************************
** Form generated from reading UI file 'fitwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FITWIDGET_H
#define FITWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "histchartview.h"
#include "npschartview.h"
#include "npswidget.h"
#include "qparabox.h"

QT_BEGIN_NAMESPACE

class Ui_NPSDockWidget
{
public:
    QWidget *dockWidgetContents;
    NPSWidget *widget;
    QPushButton *pushButton_2;
    NPSChartView *graphicsView;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton;
    HistChartView *graphicsView_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_6;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QParaBox *groupBox;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_11;
    QProgressBar *progressBar;
    QParaBox *groupBox_2;
    QLabel *label_42;
    QLabel *label_44;
    QLabel *label_47;
    QLabel *label_49;
    QPushButton *pushButton_10;

    void setupUi(QDockWidget *NPSDockWidget)
    {
        if (NPSDockWidget->objectName().isEmpty())
            NPSDockWidget->setObjectName(QStringLiteral("NPSDockWidget"));
        NPSDockWidget->resize(1200, 674);
        NPSDockWidget->setMinimumSize(QSize(1200, 470));
        NPSDockWidget->setMaximumSize(QSize(1200, 524287));
        NPSDockWidget->setCursor(QCursor(Qt::ArrowCursor));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        widget = new NPSWidget(dockWidgetContents);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1200, 682));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 0, 75, 23));
        graphicsView = new NPSChartView(widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 30, 771, 441));
        lineEdit_7 = new QLineEdit(widget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(770, 0, 51, 21));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 75, 23));
        graphicsView_2 = new HistChartView(widget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(770, 30, 431, 441));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(860, 0, 41, 21));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(220, 0, 41, 31));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 0, 31, 31));
        lineEdit_8 = new QLineEdit(widget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(1140, 0, 51, 21));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(990, 470, 31, 23));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(960, 470, 31, 23));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1100, 0, 51, 21));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(200, 0, 21, 31));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(840, 0, 21, 21));
        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(370, 470, 31, 23));
        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(340, 470, 31, 23));
        groupBox = new QParaBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 489, 391, 151));
        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(200, 30, 61, 19));
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(310, 30, 81, 19));
        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(20, 70, 41, 19));
        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(270, 30, 31, 19));
        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(20, 30, 41, 19));
        label_31 = new QLabel(groupBox);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(70, 110, 68, 19));
        label_32 = new QLabel(groupBox);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(20, 110, 31, 19));
        label_33 = new QLabel(groupBox);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(70, 30, 68, 19));
        label_34 = new QLabel(groupBox);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(150, 30, 41, 19));
        label_35 = new QLabel(groupBox);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(70, 70, 68, 19));
        label_35->setTextFormat(Qt::AutoText);
        label_36 = new QLabel(groupBox);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(150, 70, 41, 19));
        label_37 = new QLabel(groupBox);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(200, 70, 61, 19));
        label_38 = new QLabel(groupBox);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(150, 110, 51, 19));
        label_39 = new QLabel(groupBox);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(200, 110, 61, 19));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(636, 10, 71, 16));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(710, 10, 47, 16));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(516, 10, 81, 16));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(600, 10, 31, 16));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(550, 590, 211, 41));
        QFont font;
        font.setPointSize(12);
        label_5->setFont(font);
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(424, 10, 31, 16));
        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(340, 10, 81, 16));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(420, 500, 51, 31));
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(420, 550, 51, 31));
        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(490, 500, 51, 31));
        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(490, 550, 51, 31));
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(420, 610, 118, 23));
        progressBar->setValue(0);
        groupBox_2 = new QParaBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(960, 510, 201, 131));
        label_42 = new QLabel(groupBox_2);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(50, 60, 41, 19));
        label_44 = new QLabel(groupBox_2);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(50, 30, 41, 19));
        label_47 = new QLabel(groupBox_2);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(120, 30, 68, 19));
        label_49 = new QLabel(groupBox_2);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setGeometry(QRect(120, 60, 68, 19));
        label_49->setTextFormat(Qt::AutoText);
        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(50, 90, 51, 31));
        NPSDockWidget->setWidget(dockWidgetContents);

        retranslateUi(NPSDockWidget);
        QObject::connect(pushButton, SIGNAL(clicked()), graphicsView, SLOT(back()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), graphicsView, SLOT(home()));
        QObject::connect(lineEdit_7, SIGNAL(returnPressed()), graphicsView_2, SLOT(setindex()));
        QObject::connect(lineEdit_8, SIGNAL(returnPressed()), graphicsView_2, SLOT(setbin()));
        QObject::connect(graphicsView, SIGNAL(sendyaxis(double)), label_3, SLOT(setNum(double)));
        QObject::connect(graphicsView, SIGNAL(sendxaxis(double)), label, SLOT(setNum(double)));
        QObject::connect(pushButton_7, SIGNAL(clicked()), widget, SLOT(setting()));

        QMetaObject::connectSlotsByName(NPSDockWidget);
    } // setupUi

    void retranslateUi(QDockWidget *NPSDockWidget)
    {
        NPSDockWidget->setWindowTitle(QApplication::translate("NPSDockWidget", "NPS", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("NPSDockWidget", "Home", Q_NULLPTR));
        lineEdit_7->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NPSDockWidget", "Back", Q_NULLPTR));
        label_7->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_6->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        lineEdit_8->setText(QApplication::translate("NPSDockWidget", "50", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("NPSDockWidget", ">>", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("NPSDockWidget", "<<", Q_NULLPTR));
        label_9->setText(QApplication::translate("NPSDockWidget", "bin:", Q_NULLPTR));
        label_10->setText(QApplication::translate("NPSDockWidget", "/", Q_NULLPTR));
        label_11->setText(QApplication::translate("NPSDockWidget", "/", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("NPSDockWidget", ">>", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("NPSDockWidget", "<<", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("NPSDockWidget", "Fitting", Q_NULLPTR));
        label_26->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_27->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_28->setText(QApplication::translate("NPSDockWidget", "Vol:", Q_NULLPTR));
        label_29->setText(QApplication::translate("NPSDockWidget", "dt:", Q_NULLPTR));
        label_30->setText(QApplication::translate("NPSDockWidget", "Shape:", Q_NULLPTR));
        label_31->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_32->setText(QApplication::translate("NPSDockWidget", "Adj:", Q_NULLPTR));
        label_33->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_34->setText(QApplication::translate("NPSDockWidget", "Imin:", Q_NULLPTR));
        label_35->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_36->setText(QApplication::translate("NPSDockWidget", "Imax:", Q_NULLPTR));
        label_37->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_38->setText(QApplication::translate("NPSDockWidget", "Score:", Q_NULLPTR));
        label_39->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("NPSDockWidget", "ms", Q_NULLPTR));
        label_3->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("NPSDockWidget", "pA", Q_NULLPTR));
        label_5->setText(QString());
        label_12->setText(QApplication::translate("NPSDockWidget", "pA", Q_NULLPTR));
        label_13->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("NPSDockWidget", "Fit", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("NPSDockWidget", "...", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("NPSDockWidget", "Fit all", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("NPSDockWidget", "Save", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("NPSDockWidget", "Median Value", Q_NULLPTR));
        label_42->setText(QApplication::translate("NPSDockWidget", "Vol:", Q_NULLPTR));
        label_44->setText(QApplication::translate("NPSDockWidget", "Shape:", Q_NULLPTR));
        label_47->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        label_49->setText(QApplication::translate("NPSDockWidget", "0", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("NPSDockWidget", "Median", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NPSDockWidget: public Ui_NPSDockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FITWIDGET_H
