#include "determinezerosapplication.h"
#include "ui_determinezerosapplication.h"


DetermineZerosApplication::DetermineZerosApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DetermineZerosApplication)
{
    ui->setupUi(this);
    connect(ui->plot, SIGNAL(clicked()), this, SLOT(plotter()));
}

DetermineZerosApplication::~DetermineZerosApplication()
{
    delete ui;
}

void DetermineZerosApplication::plotter(){
    // generate some data:
    QVector<double> x(10000), y(10000); // initialize with entries 0..100
    for (double i=0; i<10000; i=+0.25)
    {
      x[i] = i/1000-5; // x goes from -1 to 1
      y[i] = qPow(x[i],3)+ 3*qPow(x[i],2)-x[i]-8; // let's plot a cubatic function x³+3x²-x-8
    }
    // create graph and assign data to it:
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->plot->xAxis->setRange(-10, 10);
    ui->plot->yAxis->setRange(-50, 50);
    ui->plot->replot();
}

void DetermineZerosApplication::bisection(){
    // example function f(x)= x²-2
    double leftBoundaryX = 0;
    double rightBoundaryX = 2;
    double leftBoundaryF = qPow(leftBoundaryX,2)-2;//function(leftBoundaryX);
    double rightBoundaryF =qPow(rightBoundaryX,2)-2;// function(rightBoundaryX);
    double newBoundaryX;// = (rightBoundaryX-leftBoundaryX)/2;
    double newBoundaryF;
    double oldBoundaryX;
    double oldBoundaryF;
    do{
        oldBoundaryX = newBoundaryX;
        oldBoundaryF = newBoundaryF;
        newBoundaryX = (rightBoundaryX-leftBoundaryX)/2;
        newBoundaryF = qPow(rightBoundaryX,2)-2;//function(newBoundaryX);
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
    double leftBoundaryF = qPow(leftBoundaryX,3)-2*leftBoundaryX + 2; //function(leftBoundaryX);
    double rightBoundaryF = qPow(rightBoundaryX,3)-2*rightBoundaryX + 2; //function(rightBoundaryX);
    double newBoundaryX; //= (leftBoundaryX*leftBoundaryF - rightBoundaryX*rightBoundaryF)/(rightBoundaryF-leftBoundaryF);
    double newBoundaryF;
    double oldBoundaryX;
    double oldBoundaryF;
    do{
        oldBoundaryX = newBoundaryX;
        oldBoundaryF = newBoundaryF;
        newBoundaryX = (leftBoundaryX*rightBoundaryF - rightBoundaryX*leftBoundaryF)/(rightBoundaryF-leftBoundaryF);
        newBoundaryF = qPow(newBoundaryX,3)-2*newBoundaryX + 2; //function(newBoundaryX);
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
        double f = qPow(x,3)+3*qPow(x,2)-x-8;//function(x);
        double fPrime = 3*qPow(x,2)+6*x-1;//derivativeOfFnction(x);
        x = oldX-f/fPrime;
    }
    while((int)(x*1000) != (int)(oldX*1000));
}





