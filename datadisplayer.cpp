#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include "datadisplayer.h"
#include "piecewise.h"
#include "parseTemps.h"





std::ostream& operator<<(std::ostream& outs, const LineFormula& line)
{
    std::stringstream ss;
    
    ss << std::right;
    ss << std::setprecision(0) << std::fixed;

    ss << std::setw(COL_WIDTH-10) << line.domain.first 
       << " <= x <" 
       << std::setw(COL_WIDTH-5) << line.domain.second << "; ";

    ss << std::setprecision(4);
    ss << std::left;

    ss << "y_" 
       << std::setw(COL_WIDTH-10) << line.ysub
       << std::right
       << std::setw(COL_WIDTH-10) << "=";

    int i = 0;
    for(const double &c : line.coefficients){
        ss << std::setw(COL_WIDTH-2) << c;
        if(i > 0)
            ss << "x";
        if(i > 1)
            ss << "^" << i;

        if(i < line.coefficients.size() - 1)
            ss << " +  ";
        i++;
    }
    ss << ";";

    outs << ss.str();
    return outs;
}

