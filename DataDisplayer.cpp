#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include "DataDisplayer.h"
#include "piecewise.h"
#include "parseTemps.h"





std::ostream& operator<<(std::ostream& outs, const PieceWise::LineFormula& line)
{
    std::stringstream ss;
    
    ss << std::left;
    ss << std::setprecision(4) << std::fixed;

    ss  << "y_" << std::setw(COL_WIDTH-10) << line.ysub
         << " =  "
         << std::right 
         << std::setw(COL_WIDTH) << line.b << " + " 
         << std::setw(COL_WIDTH-5) << line.m << "x; " 
         << std::setw(COL_WIDTH) << PieceWise::MATHTYPE;

    outs << ss.str();
    return outs;
}