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

std::ostream& operator<<(std::ostream& outs, const LineFormula& line);

//display single core interpolation
template <typename Output, 
          typename LineFormulaContainer = std::vector<LineFormula>>
void display(Output &outs, LineFormulaContainer &lines, const std::string &type){
    for(const LineFormula &line : lines){
        outs << line << " " << std::setw(COL_WIDTH) << type << std::endl;
    }
};

#endif