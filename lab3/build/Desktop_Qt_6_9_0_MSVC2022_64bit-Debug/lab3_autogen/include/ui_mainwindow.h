/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnGet;
    QSpacerItem *verticalSpacer;
    QPushButton *btnDelete;
    QPushButton *btnList;
    QPushButton *btnCreate;
    QPushButton *btnUpdate;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QMenuBar *menubar;
    QMenu *menuGUI;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 2, 1, 1);

        btnGet = new QPushButton(centralwidget);
        btnGet->setObjectName("btnGet");

        gridLayout->addWidget(btnGet, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName("btnDelete");

        gridLayout->addWidget(btnDelete, 2, 0, 1, 1);

        btnList = new QPushButton(centralwidget);
        btnList->setObjectName("btnList");

        gridLayout->addWidget(btnList, 1, 0, 1, 1);

        btnCreate = new QPushButton(centralwidget);
        btnCreate->setObjectName("btnCreate");

        gridLayout->addWidget(btnCreate, 4, 0, 1, 1);

        btnUpdate = new QPushButton(centralwidget);
        btnUpdate->setObjectName("btnUpdate");

        gridLayout->addWidget(btnUpdate, 3, 0, 1, 1);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setMaximum(1000);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setMaximum(1000);

        gridLayout->addWidget(spinBox_2, 2, 1, 1, 1);

        spinBox_3 = new QSpinBox(centralwidget);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setMaximum(1000);

        gridLayout->addWidget(spinBox_3, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuGUI = new QMenu(menubar);
        menuGUI->setObjectName("menuGUI");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGUI->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnGet->setText(QCoreApplication::translate("MainWindow", "get", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        btnList->setText(QCoreApplication::translate("MainWindow", "list", nullptr));
        btnCreate->setText(QCoreApplication::translate("MainWindow", "create", nullptr));
        btnUpdate->setText(QCoreApplication::translate("MainWindow", "update", nullptr));
        menuGUI->setTitle(QCoreApplication::translate("MainWindow", "GUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
