#ifndef DATADISPLAYER_INCLUDED
#define DATADISPLAYER_INCLUDED

#include<iostream>
#include <utility>
#include <vector>
#include <string>
#include "piecewise.h"
#include "parseTemps.h"



const int COL_WIDTH = 15;
const std::string BASE_FILENAME = "core_reading-";
const std::string FILE_EXT = ".txt";
const std::string FILENAME_SEPARATOR = "_";

std::ostream& operator<<(std::ostream& outs, const PieceWise::LineFormula& line);

template <typename CoreTempReadingContainer, typename OutputContainer>
void display(OutputContainer &outs, const CoreTempReadingContainer &data){
    int k = 0;
    for(auto itr = data.begin(); itr+1 != data.end(); itr++){

        double x1 = itr->first;
        //double y1 = itr->second[core];
        double x2 = (itr+1)->first;
        //double y2 = (itr+1) ->second[core];

        auto outsItr = outs.begin();
        auto y1Values = itr->second;
        auto y2Values = (itr+1)->second;
        for(auto y1Itr = y1Values.begin(), y2Itr = y2Values.begin();
                 y1Itr != y1Values.end(); ++y1Itr, ++y2Itr){
            
            double y1 = *y1Itr;
            double y2 = *y2Itr;
            
            Point p1(x1, y1);
            Point p2(x2, y2);


            PieceWise::LineFormula line = PieceWise::interpolate(p1, p2);
            line.ysub = k;
            *outsItr << line << std::endl;
            ++outsItr;
        }

        k++;
    }
} 


#endif