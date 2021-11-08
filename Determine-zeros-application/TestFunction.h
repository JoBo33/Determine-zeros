#ifndef TESTFUNCTION_H
#define TESTFUNCTION_H
#include <QtMath>



double F1(double x){
    return qPow(x,3)+3*qPow(x,2)-x-8;
}
double F2(double x){
    return qPow(x,3)-2*x + 2;
}
double F3(double x){
    return qPow(x,2)-2;
}


#endif // TESTFUNCTION_H
