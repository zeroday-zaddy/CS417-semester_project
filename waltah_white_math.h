#ifndef WALTAH_WHITE_MATH_INCLUDED
#define WALTAH_WHITE_MATH_INCLUDED

#include <utility>

using Point = std::pair<double, double>;
using Domain = std::pair<double, double>;

struct LineFormula{
    std::vector<double> coefficients;
    int ysub = 0;
    Domain domain;
    bool infiniteDomain = true;

    LineFormula(std::vector<double> coefficients = {}, int ysub = 0,
                Domain domain = {0,0}, bool infiniteDomain = true):
        coefficients(coefficients), ysub(ysub), domain(domain), 
        infiniteDomain(infiniteDomain)
        {}
};


#endif
