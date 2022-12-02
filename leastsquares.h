#ifndef LEASTSQUARES_INCLUDED
#define LEASTSQUARES_INCLUDED
#include <vector>
#include "waltah_white_math.h"
#include <algorithm>
#include <cmath>
#include <string>

class LeastSquares{
    
public:

    static const std::string MATHTYPE;

    template<typename PointContainer = std::vector<Point>>
    static LineFormula approximate(const PointContainer &data, int degree){
        LineFormula line;
        line.coefficients.resize(degree);
        if(degree == 2){
            double summation_x = 0;
            double summation_xsq = 0;
            double summation_f = 0;
            double summation_xf = 0;
            std::for_each(data.begin(), data.end(),
                [&](const Point& p){
                    summation_x += p.first;
                    summation_xsq += pow(p.first,2);
                    summation_f += p.second;
                    summation_xf += p.first * p.second;
                });
            
            int n = data.size();

            line.coefficients[1] = n * summation_xf - summation_x * summation_f;
            line.coefficients[1] /= n * summation_xsq - pow(summation_x, 2);

            line.coefficients[0] = summation_f / n - (summation_x / n) * line.coefficients[1];
            
        }
        return line;
    }
};

#endif