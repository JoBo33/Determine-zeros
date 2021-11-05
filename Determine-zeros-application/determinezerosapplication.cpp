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
 //   // example function f(x) = x³-2x+2
 //   double leftBoundaryX = -2;
 //   double rightBoundaryX = 0;
 //   double leftBoundaryF = qPow(leftBoundaryX,3)-2*leftBoundaryX + 2; //function(leftBoundaryX);
 //   double rightBoundaryF = qPow(rightBoundaryX,3)-2*rightBoundaryX + 2; //function(rightBoundaryX);
 //   double newBoundaryX; //= (leftBoundaryX*leftBoundaryF - rightBoundaryX*rightBoundaryF)/(rightBoundaryF-leftBoundaryF);
 //   double newBoundaryF;
 //   double oldBoundaryX;
 //   double oldBoundaryF;
 //   do{
 //       oldBoundaryX = newBoundaryX;
 //       oldBoundaryF = newBoundaryF;
 //       newBoundaryX = (leftBoundaryX*leftBoundaryF - rightBoundaryX*rightBoundaryF)/(rightBoundaryF-leftBoundaryF);
 //       newBoundaryF = qPow(newBoundaryX,3)-2*newBoundaryX + 2; //function(newBoundaryX);
 //       if((newBoundaryF < 0 && leftBoundaryF < 0) || (newBoundaryF > 0 && leftBoundaryF > 0)){
 //           leftBoundaryX = newBoundaryX;
 //           leftBoundaryF = newBoundaryF;
 //       }
 //       else if((newBoundaryF < 0 && rightBoundaryF < 0) || (newBoundaryF > 0 && rightBoundaryF > 0)){
 //           rightBoundaryX = newBoundaryX;
 //           rightBoundaryF = newBoundaryF;
 //       }
 //   }
 //   while((int)oldBoundaryX*1000 != (int)newBoundaryX*1000);
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





