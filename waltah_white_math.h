#ifndef WALTAH_WHITE_MATH_INCLUDED
#define WALTAH_WHITE_MATH_INCLUDED

#include <utility>

/**
 * A pair of values where the
 *   - _first_ attribute is a x value on coordinate system
 *   - _second attribute is a y value on coordinate system
 */
using Point = std::pair<double, double>;

/**
 * A pair of values where the
 *   - _first_ attribute is the starting x value on coordinate system
 *   - _second attribute is the ending x value on coordinate system
 */
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
