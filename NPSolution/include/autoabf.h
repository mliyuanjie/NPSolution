/********************************************************************************
** Form generated from reading UI file 'autoabf.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef AUTOABF_H
#define AUTOABF_H

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
#include "autowidget.h"
#include "npschartview.h"

QT_BEGIN_NAMESPACE

class Ui_AUTODockWidget
{
public:
    AUTOWidget *dockWidgetContents;
    NPSChartView *graphicsView;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QProgressBar *progressBar;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLabel *label_13;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;
    QPushButton *pushButton_10;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_13;
    QLineEdit *lineEdit_6;
    QLabel *label_10;

    void setupUi(QDockWidget *AUTODockWidget)
    {
        if (AUTODockWidget->objectName().isEmpty())
            AUTODockWidget->setObjectName(QStringLiteral("AUTODockWidget"));
        AUTODockWidget->resize(1200, 478);
        AUTODockWidget->setMinimumSize(QSize(1200, 470));
        AUTODockWidget->setMaximumSize(QSize(1200, 524287));
        AUTODockWidget->setCursor(QCursor(Qt::ArrowCursor));
        dockWidgetContents = new AUTOWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        graphicsView = new NPSChartView(dockWidgetContents);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(11, 48, 991, 361));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        label_9 = new QLabel(dockWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1030, 260, 111, 18));
        lineEdit_3 = new QLineEdit(dockWidgetContents);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(1030, 290, 113, 25));
        progressBar = new QProgressBar(dockWidgetContents);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(1020, 400, 161, 23));
        progressBar->setValue(0);
        label_7 = new QLabel(dockWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1030, 20, 121, 18));
        label_8 = new QLabel(dockWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1030, 100, 121, 18));
        lineEdit = new QLineEdit(dockWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(1030, 50, 111, 25));
        label_13 = new QLabel(dockWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(1030, 180, 121, 18));
        lineEdit_2 = new QLineEdit(dockWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(1030, 130, 113, 25));
        lineEdit_4 = new QLineEdit(dockWidgetContents);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(1030, 210, 113, 25));
        pushButton_2 = new QPushButton(dockWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 10, 51, 28));
        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(530, 10, 51, 28));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(940, 0, 61, 51));
        lineEdit_5 = new QLineEdit(dockWidgetContents);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(870, 10, 41, 31));
        pushButton_4 = new QPushButton(dockWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 10, 71, 28));
        pushButton_5 = new QPushButton(dockWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(90, 10, 71, 28));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 410, 661, 31));
        pushButton_10 = new QPushButton(dockWidgetContents);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(170, 10, 71, 28));
        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(710, 410, 141, 31));
        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(870, 410, 131, 31));
        pushButton_13 = new QPushButton(dockWidgetContents);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(250, 10, 71, 28));
        lineEdit_6 = new QLineEdit(dockWidgetContents);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(1030, 360, 113, 25));
        label_10 = new QLabel(dockWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1030, 330, 111, 18));
        AUTODockWidget->setWidget(dockWidgetContents);

        retranslateUi(AUTODockWidget);
        QObject::connect(pushButton_4, SIGNAL(clicked()), graphicsView, SLOT(home()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), graphicsView, SLOT(back()));

        QMetaObject::connectSlotsByName(AUTODockWidget);
    } // setupUi

    void retranslateUi(QDockWidget *AUTODockWidget)
    {
        AUTODockWidget->setWindowTitle(QApplication::translate("AUTODockWidget", "Auto", Q_NULLPTR));
        label_9->setText(QApplication::translate("AUTODockWidget", "Threshold:", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("AUTODockWidget", "5", Q_NULLPTR));
        label_7->setText(QApplication::translate("AUTODockWidget", "Sigma:", Q_NULLPTR));
        label_8->setText(QApplication::translate("AUTODockWidget", "Window Size:", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("AUTODockWidget", "10", Q_NULLPTR));
        label_13->setText(QApplication::translate("AUTODockWidget", "Frequence(k):", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("AUTODockWidget", "10", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("AUTODockWidget", "500", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("AUTODockWidget", ">>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AUTODockWidget", "<<", Q_NULLPTR));
        label_2->setText(QApplication::translate("AUTODockWidget", "0", Q_NULLPTR));
        lineEdit_5->setText(QApplication::translate("AUTODockWidget", "0", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("AUTODockWidget", "Home", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("AUTODockWidget", "Back", Q_NULLPTR));
        label->setText(QApplication::translate("AUTODockWidget", "C://", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("AUTODockWidget", "Remove", Q_NULLPTR));
        label_3->setText(QApplication::translate("AUTODockWidget", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("AUTODockWidget", "0", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("AUTODockWidget", "Start", Q_NULLPTR));
        lineEdit_6->setText(QApplication::translate("AUTODockWidget", "Result", Q_NULLPTR));
        label_10->setText(QApplication::translate("AUTODockWidget", "Name:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AUTODockWidget: public Ui_AUTODockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // AUTOABF_H
