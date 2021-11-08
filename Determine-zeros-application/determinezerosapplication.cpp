#include "determinezerosapplication.h"
#include "ui_determinezerosapplication.h"
#include "TestFunction.h"

DetermineZerosApplication::DetermineZerosApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DetermineZerosApplication)
{
    ui->setupUi(this);
    connect(ui->pushButtonShow, SIGNAL(clicked()), this, SLOT(buttonShowClicked()));

    FunctionPointer = F1;
}

DetermineZerosApplication::~DetermineZerosApplication()
{
    delete ui;
}

void DetermineZerosApplication::buttonShowClicked(){
    if(ui->radioButtonBisection->isChecked()){
        FunctionPointer = F3;
        bisection();
    }
    else if(ui->radioButtonRegulaFalsi->isChecked()){
        FunctionPointer = F2;
        regulaFalsi();
    }
    else if(ui->radioButtonNewton->isChecked()){
        FunctionPointer = F1;
        newtonRaphson();
    }
    connect(ui->plot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(plotter()));

    plotter();
}

void DetermineZerosApplication::plotter(){

    double lower = ui->plot->xAxis->range().lower;
    double upper = ui->plot->xAxis->range().upper;

    // generate some data:
    QVector<double> x(10000), y(10000); // initialize with entries 0..100
    for (double i=0; i<10000; i+=0.1)
    {
      x[i] = i/(upper-lower)+lower;
      y[i] = FunctionPointer(x[i]); //x³+3x²-x-8
    }
    // create graph and assign data to it:
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");

    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->plot->replot();
}

double hMethod(std::function<double(double)> func, double x){
    double h = 0.0001;

    double slope = (func(x+h)-func(x))/h;

    return slope;
}

void DetermineZerosApplication::bisection(){
    // example function f(x)= x²-2
    double leftBoundaryX = 0;
    double rightBoundaryX = 2;
    double leftBoundaryF = FunctionPointer(leftBoundaryX);//function(leftBoundaryX);
    double rightBoundaryF =FunctionPointer(rightBoundaryX);// function(rightBoundaryX);
    double newBoundaryX;// =(rightBoundaryX-leftBoundaryX)/2;
    double newBoundaryF;
    double oldBoundaryX;
    double oldBoundaryF;
    do{
        oldBoundaryX = newBoundaryX;
        oldBoundaryF = newBoundaryF;
        newBoundaryX = (rightBoundaryX-leftBoundaryX)/2;
        newBoundaryF = FunctionPointer(newBoundaryX);//function(newBoundaryX);
        if((newBoundaryF < 0 && leftBoundaryF < 0) || (newBoundaryF > 0 && leftBoundaryF > 0)){
            leftBoundaryX = newBoundaryX;
            leftBoundaryF = newBoundaryF;
        }
        else if((newBoundaryF < 0 && rightBoundaryF < 0) || (newBoundaryF > 0 && rightBoundaryF > 0)){
            rightBoundaryX = newBoundaryX;
            rightBoundaryF = newBoundaryF;
        }
    }
    while((int)(oldBoundaryX*1000) != (int)(newBoundaryX*1000));
}
void DetermineZerosApplication::regulaFalsi(){
    // example function f(x) = x³-2x+2
    double leftBoundaryX = -2;
    double rightBoundaryX = 0;
    double leftBoundaryF = FunctionPointer(leftBoundaryX); //function(leftBoundaryX);
    double rightBoundaryF = FunctionPointer(rightBoundaryX); //function(rightBoundaryX);
    double newBoundaryX; //= (leftBoundaryX*leftBoundaryF - rightBoundaryX*rightBoundaryF)/(rightBoundaryF-leftBoundaryF);
    double newBoundaryF;
    double oldBoundaryX;
    double oldBoundaryF;
    do{
        oldBoundaryX = newBoundaryX;
        oldBoundaryF = newBoundaryF;
        newBoundaryX = (leftBoundaryX*rightBoundaryF - rightBoundaryX*leftBoundaryF)/(rightBoundaryF-leftBoundaryF);
        newBoundaryF = FunctionPointer(newBoundaryX); //function(newBoundaryX);
        if((newBoundaryF < 0 && leftBoundaryF < 0) || (newBoundaryF > 0 && leftBoundaryF > 0)){
            leftBoundaryX = newBoundaryX;
            leftBoundaryF = newBoundaryF;
        }
        else if((newBoundaryF < 0 && rightBoundaryF < 0) || (newBoundaryF > 0 && rightBoundaryF > 0)){
            rightBoundaryX = newBoundaryX;
            rightBoundaryF = newBoundaryF;
        }
    }
    while((int)(oldBoundaryX*1000) != (int)(newBoundaryX*1000));
}
void DetermineZerosApplication::newtonRaphson(){
    // example function f(x) = x³+3x²-x-8
    double x = 1;
    double oldX;
    do{
        oldX=x;
        double f = FunctionPointer(x);//function(x);
        double fPrime = hMethod(FunctionPointer,x); // 3*qPow(x,2)+6*x-1; //derivativeOfFunction(x);
        x = oldX-f/fPrime;
    }
    while((int)(x*1000) != (int)(oldX*1000));
}





