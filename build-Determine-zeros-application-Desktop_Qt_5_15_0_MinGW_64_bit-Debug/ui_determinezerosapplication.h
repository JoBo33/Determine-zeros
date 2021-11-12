/********************************************************************************
** Form generated from reading UI file 'determinezerosapplication.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETERMINEZEROSAPPLICATION_H
#define UI_DETERMINEZEROSAPPLICATION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_DetermineZerosApplication
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonBisection;
    QRadioButton *radioButtonRegulaFalsi;
    QRadioButton *radioButtonNewton;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxStart;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBoxEnd;
    QLabel *label_3;
    QSpinBox *spinBoxAccuracy;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButtonShow;
    QSpacerItem *verticalSpacer;
    QCustomPlot *plot;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidgetZerosIterations;

    void setupUi(QMainWindow *DetermineZerosApplication)
    {
        if (DetermineZerosApplication->objectName().isEmpty())
            DetermineZerosApplication->setObjectName(QString::fromUtf8("DetermineZerosApplication"));
        DetermineZerosApplication->resize(1170, 534);
        DetermineZerosApplication->setMinimumSize(QSize(800, 400));
        centralwidget = new QWidget(DetermineZerosApplication);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
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

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        doubleSpinBoxStart = new QDoubleSpinBox(groupBox);
        doubleSpinBoxStart->setObjectName(QString::fromUtf8("doubleSpinBoxStart"));
        doubleSpinBoxStart->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBoxStart->setMinimum(-99.989999999999995);

        verticalLayout->addWidget(doubleSpinBoxStart);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        doubleSpinBoxEnd = new QDoubleSpinBox(groupBox);
        doubleSpinBoxEnd->setObjectName(QString::fromUtf8("doubleSpinBoxEnd"));
        doubleSpinBoxEnd->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        doubleSpinBoxEnd->setMinimum(-99.989999999999995);

        verticalLayout->addWidget(doubleSpinBoxEnd);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        spinBoxAccuracy = new QSpinBox(groupBox);
        spinBoxAccuracy->setObjectName(QString::fromUtf8("spinBoxAccuracy"));
        spinBoxAccuracy->setMinimum(1);
        spinBoxAccuracy->setMaximum(9);
        spinBoxAccuracy->setValue(3);

        verticalLayout->addWidget(spinBoxAccuracy);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMaximumSize(QSize(200, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        pushButtonShow = new QPushButton(groupBox_2);
        pushButtonShow->setObjectName(QString::fromUtf8("pushButtonShow"));

        verticalLayout_2->addWidget(pushButtonShow);


        verticalLayout_3->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_3);

        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(plot);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetMaximumSize);
        tableWidgetZerosIterations = new QTableWidget(centralwidget);
        tableWidgetZerosIterations->setObjectName(QString::fromUtf8("tableWidgetZerosIterations"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidgetZerosIterations->sizePolicy().hasHeightForWidth());
        tableWidgetZerosIterations->setSizePolicy(sizePolicy3);
        tableWidgetZerosIterations->setMaximumSize(QSize(500, 2000));
        tableWidgetZerosIterations->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetZerosIterations->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(tableWidgetZerosIterations);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalLayout_2->setStretch(1, 4);
        horizontalLayout_2->setStretch(2, 3);

        horizontalLayout_3->addLayout(horizontalLayout_2);

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
        label->setText(QCoreApplication::translate("DetermineZerosApplication", "Intervalstart/Startpoint", nullptr));
        label_2->setText(QCoreApplication::translate("DetermineZerosApplication", "Intervalend", nullptr));
        label_3->setText(QCoreApplication::translate("DetermineZerosApplication", "Accuracy (in decimal places)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DetermineZerosApplication", "Enter function", nullptr));
        pushButtonShow->setText(QCoreApplication::translate("DetermineZerosApplication", "Show", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetermineZerosApplication: public Ui_DetermineZerosApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETERMINEZEROSAPPLICATION_H
