#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include "DataDisplayer.h"
#include "piecewise.h"
#include "parseTemps.h"





std::ostream& operator<<(std::ostream& outs, const LineFormula& line)
{
    std::stringstream ss;
    
    ss << std::left;
    ss << std::setprecision(4) << std::fixed;

    ss  << "y_" << std::setw(COL_WIDTH-10) << line.ysub
         << " =  "
         << std::right 
         << std::setw(COL_WIDTH) << line.coefficients[1] << " + " 
         << std::setw(COL_WIDTH-5) << line.coefficients[0] << "x;";

    outs << ss.str();
    return outs;
}

