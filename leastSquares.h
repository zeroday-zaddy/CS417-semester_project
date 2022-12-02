#include <vector>
#include "point.h"
#include <algorithm>
#include <cmath>

class LeastSquares{
    std::vector<Point>& inputs;
    
    std::vector<double> coefficients;
public:
    LeastSquares(std::vector<Point>& inputs):
    inputs(inputs)
    {}

    void approximate(int degree){
        coefficients.clear();
        coefficients.resize(degree);
        if(degree == 2){
            double summation_x = 0;
            double summation_xsq = 0;
            double summation_f = 0;
            double summation_xf = 0;
            std::for_each(inputs.begin(), inputs.end(),
                [&](Point& p){
                    summation_x += p.first;
                    summation_xsq += pow(p.first,2);
                    summation_f += p.second;
                    summation_xf += p.first * p.second;
                });
            
            int n = inputs.size();

            coefficients[1] = n * summation_xf - summation_x * summation_f;
            coefficients[1] /= n * summation_xsq - pow(summation_x, 2);

            coefficients[0] = summation_f / n - (summation_x / n) * coefficients[1];
            
        }
    }
};