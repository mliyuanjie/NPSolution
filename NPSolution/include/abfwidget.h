/********************************************************************************
** Form generated from reading UI file 'abfwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABFWIDGET_H
#define ABFWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "achartview.h"

QT_BEGIN_NAMESPACE

class Ui_ABFDockWidget
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    AChartView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_14;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label;
    QLabel *label_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_15;
    QWidget *tab_2;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLabel *label_9;
    QPushButton *pushButton_11;
    QLabel *label_3;
    QProgressBar *progressBar;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QLabel *label_13;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_16;

    void setupUi(QDockWidget *ABFDockWidget)
    {
        if (ABFDockWidget->objectName().isEmpty())
            ABFDockWidget->setObjectName(QStringLiteral("ABFDockWidget"));
        ABFDockWidget->resize(1200, 604);
        ABFDockWidget->setMinimumSize(QSize(1200, 536));
        ABFDockWidget->setMaximumSize(QSize(1200, 524287));
        ABFDockWidget->setCursor(QCursor(Qt::ArrowCursor));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(dockWidgetContents);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(20, 100));
        pushButton_8->setMaximumSize(QSize(20, 20));

        verticalLayout->addWidget(pushButton_8);

        pushButton_7 = new QPushButton(dockWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setMinimumSize(QSize(20, 100));
        pushButton_7->setMaximumSize(QSize(20, 20));

        verticalLayout->addWidget(pushButton_7);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 2);

        graphicsView = new AChartView(dockWidgetContents);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));

        gridLayout->addWidget(graphicsView, 1, 5, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_9 = new QPushButton(dockWidgetContents);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(100, 20));
        pushButton_9->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(dockWidgetContents);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(100, 20));
        pushButton_10->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_10);

        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);


        gridLayout->addLayout(horizontalLayout_2, 3, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(dockWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(dockWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_14 = new QPushButton(dockWidgetContents);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        horizontalLayout->addWidget(pushButton_14);

        lineEdit_5 = new QLineEdit(dockWidgetContents);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setEnabled(true);
        lineEdit_5->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(lineEdit_5);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label_2);

        label_18 = new QLabel(dockWidgetContents);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(label_18);

        label_19 = new QLabel(dockWidgetContents);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(label_19);

        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(label);

        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(label_4);


        gridLayout->addLayout(horizontalLayout, 0, 5, 1, 1);

        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(200, 0));
        tabWidget->setMaximumSize(QSize(200, 16777215));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(60, 0));
        pushButton_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(60, 0));
        pushButton_5->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(170, 0));
        tableWidget->setMaximumSize(QSize(170, 16777215));
        tableWidget->setLineWidth(1);
        tableWidget->setMidLineWidth(0);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(75);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(60, 0));
        pushButton_6->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(pushButton_6);

        pushButton_15 = new QPushButton(tab);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(pushButton_15);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 10, 121, 18));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 30, 113, 25));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 80, 113, 25));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 60, 121, 18));
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 230, 113, 25));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 210, 111, 18));
        pushButton_11 = new QPushButton(tab_2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(20, 290, 112, 34));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 380, 91, 20));
        progressBar = new QProgressBar(tab_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 260, 161, 23));
        progressBar->setValue(0);
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 380, 41, 18));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 340, 47, 13));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 360, 31, 16));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(80, 340, 101, 16));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(80, 360, 101, 16));
        pushButton_12 = new QPushButton(tab_2);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(20, 410, 111, 34));
        pushButton_13 = new QPushButton(tab_2);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(20, 110, 112, 34));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 160, 121, 18));
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(20, 180, 113, 25));
        pushButton_16 = new QPushButton(tab_2);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(20, 460, 111, 34));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 6, 4, 1);

        ABFDockWidget->setWidget(dockWidgetContents);

        retranslateUi(ABFDockWidget);
        QObject::connect(pushButton_7, SIGNAL(clicked()), graphicsView, SLOT(changey2()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), graphicsView, SLOT(changey1()));
        QObject::connect(pushButton, SIGNAL(clicked()), graphicsView, SLOT(back()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), graphicsView, SLOT(changex1()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), graphicsView, SLOT(changex2()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), graphicsView, SLOT(additem()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), graphicsView, SLOT(delitem()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), graphicsView, SLOT(save()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), graphicsView, SLOT(startprocess()));
        QObject::connect(graphicsView, SIGNAL(setsignum(QString)), label_3, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(setprocess(int)), progressBar, SLOT(setValue(int)));
        QObject::connect(graphicsView, SIGNAL(setmean(QString)), label_16, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(setSD(QString)), label_17, SLOT(setText(QString)));
        QObject::connect(graphicsView, SIGNAL(setcurrent(double)), label_19, SLOT(setNum(double)));
        QObject::connect(pushButton_12, SIGNAL(clicked()), graphicsView, SLOT(savesig()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), graphicsView, SLOT(home()));
        QObject::connect(graphicsView, SIGNAL(settime(double)), label_4, SLOT(setNum(double)));
        QObject::connect(pushButton_13, SIGNAL(clicked()), graphicsView, SLOT(startsmooth()));
        QObject::connect(lineEdit_4, SIGNAL(returnPressed()), graphicsView, SLOT(setinterval()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ABFDockWidget);
    } // setupUi

    void retranslateUi(QDockWidget *ABFDockWidget)
    {
        ABFDockWidget->setWindowTitle(QApplication::translate("ABFDockWidget", "ABF", Q_NULLPTR));
        pushButton_8->setText(QString());
        pushButton_7->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
        label_5->setText(QApplication::translate("ABFDockWidget", "filename://", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ABFDockWidget", "Back", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ABFDockWidget", "Home", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ABFDockWidget", "<<", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("ABFDockWidget", ">>", Q_NULLPTR));
        lineEdit_5->setText(QApplication::translate("ABFDockWidget", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("ABFDockWidget", "0", Q_NULLPTR));
        label_18->setText(QApplication::translate("ABFDockWidget", "Current(pA):", Q_NULLPTR));
        label_19->setText(QString());
        label->setText(QApplication::translate("ABFDockWidget", "dt(ms):", Q_NULLPTR));
        label_4->setText(QString());
        pushButton_3->setText(QApplication::translate("ABFDockWidget", "add", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("ABFDockWidget", "del", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("ABFDockWidget", "update", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("ABFDockWidget", "remove", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ABFDockWidget", "Tab 1", Q_NULLPTR));
        label_7->setText(QApplication::translate("ABFDockWidget", "Sigma:", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("ABFDockWidget", "10", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("ABFDockWidget", "50", Q_NULLPTR));
        label_8->setText(QApplication::translate("ABFDockWidget", "Window Size:", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("ABFDockWidget", "5", Q_NULLPTR));
        label_9->setText(QApplication::translate("ABFDockWidget", "Threshold:", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("ABFDockWidget", "FindPeak", Q_NULLPTR));
        label_3->setText(QApplication::translate("ABFDockWidget", "0", Q_NULLPTR));
        label_10->setText(QApplication::translate("ABFDockWidget", "Event:", Q_NULLPTR));
        label_14->setText(QApplication::translate("ABFDockWidget", "Mean:", Q_NULLPTR));
        label_15->setText(QApplication::translate("ABFDockWidget", "SD:", Q_NULLPTR));
        label_16->setText(QApplication::translate("ABFDockWidget", "0", Q_NULLPTR));
        label_17->setText(QApplication::translate("ABFDockWidget", "0", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("ABFDockWidget", "Save", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("ABFDockWidget", "Filter", Q_NULLPTR));
        label_13->setText(QApplication::translate("ABFDockWidget", "Frequence(k):", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("ABFDockWidget", "500", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("ABFDockWidget", "Auto", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ABFDockWidget", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ABFDockWidget: public Ui_ABFDockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABFWIDGET_H
