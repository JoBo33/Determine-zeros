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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_DetermineZerosApplication
{
public:
    QWidget *centralwidget;
    QCustomPlot *plot;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonBisection;
    QRadioButton *radioButtonRegulaFalsi;
    QRadioButton *radioButtonNewton;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButtonShow;

    void setupUi(QMainWindow *DetermineZerosApplication)
    {
        if (DetermineZerosApplication->objectName().isEmpty())
            DetermineZerosApplication->setObjectName(QString::fromUtf8("DetermineZerosApplication"));
        DetermineZerosApplication->resize(800, 600);
        centralwidget = new QWidget(DetermineZerosApplication);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(230, 20, 531, 531));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 245, 521));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(formLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonBisection = new QRadioButton(groupBox);
        radioButtonBisection->setObjectName(QString::fromUtf8("radioButtonBisection"));
        radioButtonBisection->setChecked(true);

        verticalLayout->addWidget(radioButtonBisection);

        radioButtonRegulaFalsi = new QRadioButton(groupBox);
        radioButtonRegulaFalsi->setObjectName(QString::fromUtf8("radioButtonRegulaFalsi"));

        verticalLayout->addWidget(radioButtonRegulaFalsi);

        radioButtonNewton = new QRadioButton(groupBox);
        radioButtonNewton->setObjectName(QString::fromUtf8("radioButtonNewton"));

        verticalLayout->addWidget(radioButtonNewton);


        formLayout->setWidget(0, QFormLayout::LabelRole, groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer);

        groupBox_2 = new QGroupBox(formLayoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        pushButtonShow = new QPushButton(groupBox_2);
        pushButtonShow->setObjectName(QString::fromUtf8("pushButtonShow"));

        verticalLayout_2->addWidget(pushButtonShow);


        formLayout->setWidget(1, QFormLayout::LabelRole, groupBox_2);

        DetermineZerosApplication->setCentralWidget(centralwidget);

        retranslateUi(DetermineZerosApplication);

        QMetaObject::connectSlotsByName(DetermineZerosApplication);
    } // setupUi

    void retranslateUi(QMainWindow *DetermineZerosApplication)
    {
        DetermineZerosApplication->setWindowTitle(QCoreApplication::translate("DetermineZerosApplication", "DetermineZerosApplication", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DetermineZerosApplication", "Choose algorithm", nullptr));
        radioButtonBisection->setText(QCoreApplication::translate("DetermineZerosApplication", "Bisection method", nullptr));
        radioButtonRegulaFalsi->setText(QCoreApplication::translate("DetermineZerosApplication", "Regula falsi", nullptr));
        radioButtonNewton->setText(QCoreApplication::translate("DetermineZerosApplication", "Newton-Raphson-method", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DetermineZerosApplication", "Enter function", nullptr));
        pushButtonShow->setText(QCoreApplication::translate("DetermineZerosApplication", "Show", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetermineZerosApplication: public Ui_DetermineZerosApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETERMINEZEROSAPPLICATION_H
