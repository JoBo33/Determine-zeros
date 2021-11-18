#ifndef DETERMINEZEROSAPPLICATION_H
#define DETERMINEZEROSAPPLICATION_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <tinyexprwrapperlibrary.h>

QT_BEGIN_NAMESPACE
namespace Ui { class DetermineZerosApplication; }
QT_END_NAMESPACE

class DetermineZerosApplication : public QMainWindow
{
    Q_OBJECT

public:
    DetermineZerosApplication(QWidget *parent = nullptr);
    ~DetermineZerosApplication();
    void bisection(double leftBoundaryX, double rightBoundaryX, unsigned long accuracy);
    void regulaFalsi(double leftBoundaryX, double rightBoundaryX, unsigned long accuracy);
    void newtonRaphson(double x, unsigned long accuracy);
    enum algorithmType{Bisection, RegulaFalsi, NewtonRaphson};
    void prepareTable(int columns, algorithmType type);
    void fillTable(double col1, double col2, double col3, double col4, double col5, double col6);
    void fillTable(double col1, double col2, double col3);
    void setRange(double centre);
    void addAlgorithmGraph();
    bool checkBoundaries(double leftBoundaryF, double rightBoundaryF);
private:
    Ui::DetermineZerosApplication *ui;
    std::function<double(double)> FunctionPointer;
    TinyExprWrapperLibrary *tinyExpr;

public slots:
    void plotter();
    void buttonShowClicked();
    void checkGroupBox();

};
#endif // DETERMINEZEROSAPPLICATION_H
