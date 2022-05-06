#include "determinezerosapplication.h"
#include "ui_determinezerosapplication.h"
#include "TestFunction.h"

DetermineZerosApplication::DetermineZerosApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DetermineZerosApplication)
{
    ui->setupUi(this);
    connect(ui->pushButtonShow, SIGNAL(clicked()), this, SLOT(buttonShowClicked()));
    connect(ui->radioButtonBisection, SIGNAL(clicked()), this, SLOT(checkGroupBox()));
    connect(ui->radioButtonNewton, SIGNAL(clicked()), this, SLOT(checkGroupBox()));
    connect(ui->radioButtonRegulaFalsi, SIGNAL(clicked()), this, SLOT(checkGroupBox()));

    // function f_ will be drawed
    //FunctionPointer = F1;

    tinyExpr = new TinyExprWrapperLibrary("");
}

DetermineZerosApplication::~DetermineZerosApplication()
{
    delete ui;
    delete tinyExpr;
}

void DetermineZerosApplication::checkGroupBox(){
    if(ui->radioButtonBisection->isChecked() || ui->radioButtonRegulaFalsi->isChecked()){
        ui->doubleSpinBoxEnd->setEnabled(true);
    }
    else if(ui->radioButtonNewton->isChecked()){
        ui->doubleSpinBoxEnd->setEnabled(false);
    }
}

void DetermineZerosApplication::prepareTable(int columns, algorithmType type){
    ui->tableWidgetZerosIterations->setColumnCount(columns);
    ui->tableWidgetZerosIterations->setRowCount(0);
    switch(type){
        case(Bisection):{
            QStringList columnHeader{"n", "an","xn","bn","f(an)","f(xn)","f(bn)"};
            ui->tableWidgetZerosIterations->setHorizontalHeaderLabels(columnHeader);
            break;
        }
        case(RegulaFalsi):{
            QStringList columnHeader{"n", "xn-1", "xn", "xn+1", "f(xn-1)", "f(xn)", "f(xn+1)"};
            ui->tableWidgetZerosIterations->setHorizontalHeaderLabels(columnHeader);
            break;
         }
        case(NewtonRaphson):{
            QStringList columnHeader{"n", "xn", "f(xn)", "f'(xn)"};
            ui->tableWidgetZerosIterations->setHorizontalHeaderLabels(columnHeader);
            break;
        }
    }
}

void DetermineZerosApplication::setRange(double centre){
    ui->plot->xAxis->setRange(centre - ui->doubleSpinBoxStart->text().toDouble(), centre + ui->doubleSpinBoxStart->text().toDouble());
    double lower = -ui->doubleSpinBoxStart->text().toDouble()/2;
    double upper = -lower;
    ui->plot->yAxis->setRange(lower,upper);
}

void DetermineZerosApplication::buttonShowClicked(){
    ui->plot->clearGraphs();
    std::string func(ui->lineEdit->text().toStdString());
    tinyExpr = new TinyExprWrapperLibrary(func);
    if(!tinyExpr->IsValid()){
        int firstErrorPos = tinyExpr->error;
        QMessageBox msg(this);
        msg.setText("Please check the the entered function at position: " + QString :: number(firstErrorPos));
        msg.exec();
        return;
    }
    plotter();
    addAlgorithmGraph();
    double leftBoundaryX = ui->doubleSpinBoxStart->text().toDouble();
    double rightBoundaryX = ui->doubleSpinBoxEnd->text().toDouble();
    QString accuracyInput = "1";
    for(int i = 0; i < ui->spinBoxAccuracy->text().toInt(); i++){
        accuracyInput.append('0');
    }
    unsigned long accuracy = accuracyInput.toULong();
    if(ui->radioButtonBisection->isChecked()){
        //FunctionPointer = F3;
        bisection(leftBoundaryX, rightBoundaryX, accuracy);
    }
    else if(ui->radioButtonRegulaFalsi->isChecked()){
        //FunctionPointer = F2;
        regulaFalsi(leftBoundaryX, rightBoundaryX, accuracy);
    }
    else if(ui->radioButtonNewton->isChecked()){
        //FunctionPointer = F1;
        newtonRaphson(leftBoundaryX, accuracy);
    }
    ui->plot->replot();
}

void DetermineZerosApplication::plotter(){
    // generate some data:
    QVector<double> x(1000001), y(1000001);
    for(int i=0; i<1000001; i++){
        x[i] = i/50.0 - 10000;
        y[i] = tinyExpr->Evaluate(x[i]);
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


void DetermineZerosApplication::fillTable(double col1, double col2, double col3, double col4, double col5, double col6){
    int rowCount = ui->tableWidgetZerosIterations->rowCount();
    ui->tableWidgetZerosIterations->insertRow(rowCount);

    QTableWidgetItem *txtC1 = new QTableWidgetItem;
    txtC1->setText(QString::number(rowCount));
    txtC1->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,0,txtC1);

    QTableWidgetItem *txtC2 = new QTableWidgetItem;
    txtC2->setText(QString::number(col1));
    txtC2->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,1,txtC2);

    QTableWidgetItem *txtC3 = new QTableWidgetItem;
    txtC3->setText(QString::number(col2));
    txtC3->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,2,txtC3);

    QTableWidgetItem *txtC4 = new QTableWidgetItem;
    txtC4->setText(QString::number(col3));
    txtC4->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,3,txtC4);

    QTableWidgetItem *txtC5 = new QTableWidgetItem;
    txtC5->setText(QString::number(col4));
    txtC5->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,4,txtC5);

    QTableWidgetItem *txtC6 = new QTableWidgetItem;
    txtC6->setText(QString::number(col5));
    txtC6->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,5,txtC6);

    QTableWidgetItem *txtC7 = new QTableWidgetItem;
    txtC7->setText(QString::number(col6));
    txtC7->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,6,txtC7);
}

void DetermineZerosApplication::fillTable(double col1, double col2, double col3){
    int rowCount = ui->tableWidgetZerosIterations->rowCount();
    ui->tableWidgetZerosIterations->insertRow(rowCount);

    QTableWidgetItem *txtC1 = new QTableWidgetItem;
    txtC1->setText(QString::number(rowCount));
    txtC1->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,0,txtC1);

    QTableWidgetItem *txtC2 = new QTableWidgetItem;
    txtC2->setText(QString::number(col1));
    txtC2->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,1,txtC2);

    QTableWidgetItem *txtC3 = new QTableWidgetItem;
    txtC3->setText(QString::number(col2));
    txtC3->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,2,txtC3);

    QTableWidgetItem *txtC4 = new QTableWidgetItem;
    txtC4->setText(QString::number(col3));
    txtC4->setTextAlignment(Qt::AlignHCenter);
    ui->tableWidgetZerosIterations->setItem(rowCount-1,3,txtC4);
}

void DetermineZerosApplication::addAlgorithmGraph(){
    ui->plot->addGraph();
    int count = ui->plot->graphCount();
    ui->plot->graph(count-1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    QPen pen;
    pen.setColor(QColor(qSin(5+1.2)*80+80, qSin(5*0.3+0)*80+80, qSin(5*0.3+1.5)*80+80) );
    ui->plot->graph(count-1)->setPen(pen);
    ui->plot->graph(ui->plot->graphCount()-1)->setLineStyle(QCPGraph::lsLine);
}

bool DetermineZerosApplication::checkBoundaries(double leftBoundaryF, double rightBoundaryF){
    if((leftBoundaryF <= 0 && rightBoundaryF <= 0) || (leftBoundaryF > 0 && rightBoundaryF > 0)){
        QMessageBox box;
        box.setText("Error! The given interval has to include exactly one zero.");
        box.exec();
        return false;
    }
    return true;
}

double hMethod(std::function<double(double)> func, double x){
    double h = 0.0001;

    double slope = (func(x+h)-func(x))/h;

    return slope;
}

void DetermineZerosApplication::bisection(double leftBoundaryX, double rightBoundaryX, unsigned long accuracy){
    // example function f(x)= x²-2
    //double leftBoundaryX = 0;
    //double rightBoundaryX = 2;

    double leftBoundaryF = tinyExpr->Evaluate(leftBoundaryX);
    double rightBoundaryF = tinyExpr->Evaluate(rightBoundaryX);
    double newBoundaryX = INFINITY;
    double newBoundaryF = INFINITY;
    double oldBoundaryX;

    prepareTable(7, Bisection);
    ui->plot->graph(ui->plot->graphCount()-1)->setLineStyle(QCPGraph::lsImpulse);
    QVector<double> x(10), y(10);
    int i = 0;
    x[i]=leftBoundaryX;
    y[i]=leftBoundaryF;
    i = 1;
    x[i]=rightBoundaryX;
    y[i]=rightBoundaryF;

    do{
        if(!checkBoundaries(leftBoundaryF, rightBoundaryF)){
            return;
        }
        if(i<9){
            i++;
        }
        oldBoundaryX = newBoundaryX;
        newBoundaryX = (rightBoundaryX-leftBoundaryX)/2+leftBoundaryX;
        newBoundaryF = tinyExpr->Evaluate(newBoundaryX);

        fillTable(leftBoundaryX,  newBoundaryX,rightBoundaryX,leftBoundaryF, newBoundaryF, rightBoundaryF);

        if((newBoundaryF < 0 && leftBoundaryF < 0) || (newBoundaryF > 0 && leftBoundaryF > 0)){
            leftBoundaryX = newBoundaryX;
            leftBoundaryF = newBoundaryF;
            x[i]=leftBoundaryX;
            y[i]=leftBoundaryF;
            if(x[i]==0){
                x[i]=leftBoundaryX;
                y[i]=leftBoundaryF;
            }
        }
        else if((newBoundaryF < 0 && rightBoundaryF < 0) || (newBoundaryF > 0 && rightBoundaryF > 0)){
            rightBoundaryX = newBoundaryX;
            rightBoundaryF = newBoundaryF;
            if(x[i]==0){
                x[i]=rightBoundaryX;
                y[i]=rightBoundaryF;
            }
        }

    }
    while((unsigned long)(oldBoundaryX*accuracy) != (unsigned long)(newBoundaryX*accuracy));
    ui->plot->graph(ui->plot->graphCount()-1)->setData(x,y);
    setRange(newBoundaryX);
}
void DetermineZerosApplication::regulaFalsi(double leftBoundaryX, double rightBoundaryX, unsigned long accuracy){
    // example function f(x) = x³-2x+2
    //double leftBoundaryX = -2;
    //double rightBoundaryX = 0;
    double leftBoundaryF = tinyExpr->Evaluate(leftBoundaryX);
    double rightBoundaryF = tinyExpr->Evaluate(rightBoundaryX);
    double newBoundaryX=INFINITY;
    double newBoundaryF=INFINITY;
    double oldBoundaryX;

    ui->plot->graph(ui->plot->graphCount()-1)->setLineStyle(QCPGraph::lsLine);
    QVector<double> x(2), y(2);
    x[0]=leftBoundaryX;
    y[0]=leftBoundaryF;
    x[1]=rightBoundaryX;
    y[1]=rightBoundaryF;
    ui->plot->graph(ui->plot->graphCount()-1)->setData(x,y);
    prepareTable(7, RegulaFalsi);
    do{
        if(!checkBoundaries(leftBoundaryF, rightBoundaryF)){
            return;
        }

        oldBoundaryX = newBoundaryX;
        newBoundaryX = (leftBoundaryX*rightBoundaryF - rightBoundaryX*leftBoundaryF)/(rightBoundaryF-leftBoundaryF);
        newBoundaryF = tinyExpr->Evaluate(newBoundaryX);

        fillTable(leftBoundaryX, rightBoundaryX, newBoundaryX,leftBoundaryF, rightBoundaryF, newBoundaryF);

        if((newBoundaryF < 0 && leftBoundaryF < 0) || (newBoundaryF > 0 && leftBoundaryF > 0)){
            leftBoundaryX = newBoundaryX;
            leftBoundaryF = newBoundaryF;
        }
        else if((newBoundaryF < 0 && rightBoundaryF < 0) || (newBoundaryF > 0 && rightBoundaryF > 0)){
            rightBoundaryX = newBoundaryX;
            rightBoundaryF = newBoundaryF;
        }
        if(ui->plot->graphCount() <= 10){
            addAlgorithmGraph();
            x[0]=leftBoundaryX;
            y[0]=leftBoundaryF;
            x[1]=rightBoundaryX;
            y[1]=rightBoundaryF;
            ui->plot->graph(ui->plot->graphCount()-1)->setData(x,y);
        }

    }
    while((unsigned long)(oldBoundaryX*accuracy) != (unsigned long)(newBoundaryX*accuracy));
    setRange(newBoundaryX);
}
void DetermineZerosApplication::newtonRaphson(double x, unsigned long accuracy){
    // example function f(x) = x³+3x²-x-8
    // diriative = 3*qPow(x,2)+6*x-1;
    // double x = 1;

    double oldX;
    prepareTable(4, NewtonRaphson);
    ui->plot->graph(ui->plot->graphCount()-1)->setLineStyle(QCPGraph::lsLine);
    QVector<double> xValues(50), y(50);
    int i = -1;

    do{
        oldX=x;
        double f = tinyExpr->Evaluate(x);
        double fPrime = tinyExpr->Derivative(x);

        fillTable(x,f,fPrime);

        x = oldX-f/fPrime;

        if(i < 49){
            i++;
            xValues[i]=oldX;
            y[i] = f;
        }
        if(i < 49){
            i++;
            xValues[i]=x;
            y[i] = 0;
        }
    }
    while((unsigned long)(x*accuracy) != (unsigned long)(oldX*accuracy));
    while(xValues[xValues.length()-1] == 0 && xValues.length() > 1){
        xValues.resize(xValues.length()-1);
        y.resize(y.length()-1);
    }
    ui->plot->graph(ui->plot->graphCount()-1)->setData(xValues,y, true);
    setRange(x);
}





