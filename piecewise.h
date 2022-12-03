#ifndef PIECEWISE_INCLUDED
#define PIECEWISE_INCLUDED

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "piecewise.h"
#include "processor.h"
#include "waltah_white_math.h"

class PieceWise{
    
    public:
    
    static const std::string MATHTYPE;
    
    
    /**
     * produce a linear LineFormula from two points
     *
     * @param p1 first point
     * @param p2 second point
     */
    static LineFormula interpolate(const Point &p1, const Point &p2){
        double dy = p2.second - p1.second;
        double dx = p2.first - p1.first;

        double slope = dy/dx;
        
        double yintercept = p1.second - slope * p1.first;


        LineFormula line {{yintercept, slope}};
        return line;
    }


    /**
     * produce a piecewise linear interpolaion in the form of a container of LineFormula
     *
     * @tparam LineFormulaContainer option to change container of LineFormula
     * @param data SingleCoreTempReading to calculate with
     * 
     * @return a container of LineFormula representing the piecewise linear interpolaion  
     */
    template<typename LineFormulaContainer = std::vector<LineFormula>>
    static LineFormulaContainer linearly_interpolate (const SingleCoreTempReading &data){
        LineFormulaContainer lines;
        int k = 0;
        for(auto itr = data.begin(); itr+1 != data.end(); itr++){

            double x1 = itr->first;
            double y1 = itr->second;
            double x2 = (itr+1)->first;
            double y2 = (itr+1) ->second;

            Point p1(x1, y1);
            Point p2(x2, y2);
            
            LineFormula line = PieceWise::interpolate(p1, p2);
            line.ysub = k;
            line.infiniteDomain = false;
            line.domain = {x1, x2};
            lines.push_back(line);

            k++;
        }

        return lines;
    }
};



#endif