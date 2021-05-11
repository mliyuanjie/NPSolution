/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ftreeview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actioncheck_signals;
    QAction *actionfit_signals;
    QAction *actionTerminal;
    QAction *actionSetting;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuPython;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    FTreeView *treeView;
    QDockWidget *fileWidget;
    QWidget *dockWidgetContents_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1576, 723);
        MainWindow->setMinimumSize(QSize(1000, 588));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actioncheck_signals = new QAction(MainWindow);
        actioncheck_signals->setObjectName(QStringLiteral("actioncheck_signals"));
        actionfit_signals = new QAction(MainWindow);
        actionfit_signals->setObjectName(QStringLiteral("actionfit_signals"));
        actionTerminal = new QAction(MainWindow);
        actionTerminal->setObjectName(QStringLiteral("actionTerminal"));
        actionSetting = new QAction(MainWindow);
        actionSetting->setObjectName(QStringLiteral("actionSetting"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1576, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuPython = new QMenu(menubar);
        menuPython->setObjectName(QStringLiteral("menuPython"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(348, 197));
        dockWidget->setMaximumSize(QSize(348, 524287));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(dockWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        treeView = new FTreeView(dockWidgetContents);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout->addWidget(treeView);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        fileWidget = new QDockWidget(MainWindow);
        fileWidget->setObjectName(QStringLiteral("fileWidget"));
        fileWidget->setMinimumSize(QSize(1200, 588));
        fileWidget->setMaximumSize(QSize(1200, 524287));
        fileWidget->setSizeIncrement(QSize(1000, 588));
        fileWidget->setBaseSize(QSize(1000, 588));
        fileWidget->setCursor(QCursor(Qt::CrossCursor));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        fileWidget->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), fileWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuPython->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew);
        menuTools->addAction(actioncheck_signals);
        menuTools->addAction(actionfit_signals);
        menuPython->addAction(actionTerminal);
        menuPython->addAction(actionSetting);

        retranslateUi(MainWindow);
        QObject::connect(treeView, SIGNAL(rootpath(QString)), lineEdit, SLOT(setText(QString)));
        QObject::connect(actionOpen, SIGNAL(triggered()), treeView, SLOT(open()));
        QObject::connect(treeView, SIGNAL(doubleClicked()), fileWidget, SLOT(show()));
        QObject::connect(actionNew, SIGNAL(triggered()), treeView, SLOT(newtask()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
        actioncheck_signals->setText(QApplication::translate("MainWindow", "check signals", Q_NULLPTR));
        actionfit_signals->setText(QApplication::translate("MainWindow", "fit signals", Q_NULLPTR));
        actionTerminal->setText(QApplication::translate("MainWindow", "Terminal", Q_NULLPTR));
        actionSetting->setText(QApplication::translate("MainWindow", "Setting", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuPython->setTitle(QApplication::translate("MainWindow", "Python", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H
