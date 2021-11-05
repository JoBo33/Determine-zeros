#include "determinezerosapplication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DetermineZerosApplication w;
    w.bisection();
    w.regulaFalsi();
    w.newtonRaphson();
    w.show();
    return a.exec();
}
