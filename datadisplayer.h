#ifndef DATADISPLAYER_INCLUDED
#define DATADISPLAYER_INCLUDED

#include<iostream>
#include <utility>
#include <vector>
#include <string>
#include "piecewise.h"
#include "leastsquares.h"
#include "parseTemps.h"
#include "waltah_white_math.h"



const int COL_WIDTH = 15;
const std::string BASE_FILENAME = "core_reading-";
const std::string FILE_EXT = ".txt";
const std::string FILENAME_SEPARATOR = "_";

/**
 * output a line formula
 *
 * @param outs where to output
 * @param line the line
 * @return the output 
 */
std::ostream& operator<<(std::ostream& outs, const LineFormula& line);


/**
 * display single core interpolation
 *
 * @tparam Output the ouput type
 * @tparam LineFormulaContainer the container for LineFormula
 * @param outs where to output
 * @param lines container of LineFormula
 * @param type the calculation type that is printed at end 
 */
template <typename Output, 
          typename LineFormulaContainer = std::vector<LineFormula>>
void display(Output &outs, LineFormulaContainer &lines, const std::string &type){
    for(const LineFormula &line : lines){
        outs << line << " " << std::setw(COL_WIDTH) << type << std::endl;
    }
};

#endif