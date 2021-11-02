/********************************************************************************
** Form generated from reading UI file 'determinezerosapplication.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETERMINEZEROSAPPLICATION_H
#define UI_DETERMINEZEROSAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetermineZerosApplication
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DetermineZerosApplication)
    {
        if (DetermineZerosApplication->objectName().isEmpty())
            DetermineZerosApplication->setObjectName(QString::fromUtf8("DetermineZerosApplication"));
        DetermineZerosApplication->resize(800, 600);
        centralwidget = new QWidget(DetermineZerosApplication);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        DetermineZerosApplication->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DetermineZerosApplication);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        DetermineZerosApplication->setMenuBar(menubar);
        statusbar = new QStatusBar(DetermineZerosApplication);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DetermineZerosApplication->setStatusBar(statusbar);

        retranslateUi(DetermineZerosApplication);

        QMetaObject::connectSlotsByName(DetermineZerosApplication);
    } // setupUi

    void retranslateUi(QMainWindow *DetermineZerosApplication)
    {
        DetermineZerosApplication->setWindowTitle(QCoreApplication::translate("DetermineZerosApplication", "DetermineZerosApplication", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetermineZerosApplication: public Ui_DetermineZerosApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETERMINEZEROSAPPLICATION_H
