#include "tinyexprwrapperlibrary.h"

TinyExprWrapperLibrary::TinyExprWrapperLibrary(std::string function)
{
    expression = te_compile(function.c_str(), vars, 1, &error);
}

TinyExprWrapperLibrary::~TinyExprWrapperLibrary()
{
    te_free(expression);
}

double TinyExprWrapperLibrary::Evaluate(double x)
{
    this->x = x;
    if (expression)
        return te_eval(expression);

    return NULL;
}

double TinyExprWrapperLibrary::Derivative(double x, double h)
{
    return (this->Evaluate(x + h) - this->Evaluate(x)) / h;
}
