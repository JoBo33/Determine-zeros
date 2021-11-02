#ifndef DETERMINEZEROSAPPLICATION_H
#define DETERMINEZEROSAPPLICATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DetermineZerosApplication; }
QT_END_NAMESPACE

class DetermineZerosApplication : public QMainWindow
{
    Q_OBJECT

public:
    DetermineZerosApplication(QWidget *parent = nullptr);
    ~DetermineZerosApplication();

private:
    Ui::DetermineZerosApplication *ui;
};
#endif // DETERMINEZEROSAPPLICATION_H
