#ifndef PIECEWISE_INCLUDED
#define PIECEWISE_INCLUDED

#include <iostream>
#include <utility>
#include <string>
#include "piecewise.h"
#include "point.h"

class PieceWise{
    public:
    
    static const std::string MATHTYPE;

    struct LineFormula{
        double m = 0;
        double b = 0;
        int ysub = 0;

        LineFormula(double m = 0, double b = 0, int ysub = 0):
            m(m), b(b), ysub(ysub){}
    };


    static LineFormula interpolate(const Point &p1, const Point &p2){
        double dy = p2.second - p1.second;
        double dx = p2.first - p1.first;

        double slope = dy/dx;
        
        double yintercept = p1.second - slope * p1.first;


        LineFormula line {slope, yintercept};
        return line;
    }

};



#endif