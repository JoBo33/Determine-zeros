#ifndef TINYEXPRWRAPPERLIBRARY_H
#define TINYEXPRWRAPPERLIBRARY_H

#include "TinyExprWrapperLibrary_global.h"
#include <string>
#include "tinyexpr.h"

class TINYEXPRWRAPPERLIBRARY_EXPORT TinyExprWrapperLibrary
{
public:
    TinyExprWrapperLibrary(std::string function);
    ~TinyExprWrapperLibrary();
    double Evaluate(double x);
    bool IsValid() { return expression; }
    double Derivative(double x, double h = 0.000001);
    int error = 0;

private:
    double x = 0;
    te_variable vars[1] = { {"x", &x} };
    te_expr* expression;
};

#endif // TINYEXPRWRAPPERLIBRARY_H
