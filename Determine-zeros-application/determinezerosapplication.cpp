#include "determinezerosapplication.h"
#include "ui_determinezerosapplication.h"

DetermineZerosApplication::DetermineZerosApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DetermineZerosApplication)
{
    ui->setupUi(this);
}

DetermineZerosApplication::~DetermineZerosApplication()
{
    delete ui;
}

