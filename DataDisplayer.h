#ifndef DATADISPLAYER_INCLUDED
#define DATADISPLAYER_INCLUDED

#include<iostream>
#include <utility>
#include <vector>
#include <string>
#include "piecewise.h"
#include "parseTemps.h"



const int COL_WIDTH = 15;

std::ostream& operator<<(std::ostream& outs, const PieceWise::LineFormula& line);

template <class CoreTempReadingContainer>
void display(std::ostream& outs, const CoreTempReadingContainer &data, int core){
    int k = 0;
    for(auto itr = data.begin(); itr+1 != data.end(); itr++){
        
        Point p1(itr->first , itr->second[core]);
        Point p2((itr+1)->first , ((itr+1)->second[core]));


        PieceWise::LineFormula line = PieceWise::interpolate(p1, p2);
        line.ysub = k;
        outs << line << std::endl;
        k++;
    }
} 


#endif