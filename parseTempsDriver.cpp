#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <iterator>
#include <algorithm>
#include <utility>

#include "parseTemps.h"
#include "processor.h"
#include "piecewise.h"
#include "leastsquares.h"
#include "datadisplayer.h"

using namespace std;

//------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    // Input validation
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file_name" << "\n";
        return 1;
    }

    ifstream input_temps(argv[1]);
    if (!input_temps) {
        cout << "ERROR: " << argv[1] << " could not be opened" << "\n";
        return 2;
    }
    // End Input Validation

    // vector
    auto readings = parse_raw_temps<std::vector<CoreTempReading>>(input_temps);
    if (readings.empty()) return 0;
    
    std::vector<SingleCoreTempReading> singleCoreReadings;
    processByCore<std::vector<CoreTempReading>, std::vector<SingleCoreTempReading>>(readings, singleCoreReadings);

    // list
    // auto readings = parse_raw_temps<std::list<CoreTempReading>>(input_temps);

    // Output everything to match the20:36:5 Python version
    for (const CoreTempReading& theReading : readings) {
        cout << "(" << theReading.first << ", [";

        const vector<double>& coreTemps = theReading.second;
        for (int i = 0; i < coreTemps.size() - 1; i++) {
            cout << coreTemps[i] << ", ";
        }
        cout << *(coreTemps.end() - 1) << "])" << "\n";
    }

    //----LINEAR INTERPOLATION


    std::vector<ofstream> piecewise_outs(singleCoreReadings.size());
    int k = 0;
    for(auto &out : piecewise_outs){
        std::string name = BASE_FILENAME + to_string(k) + 
                           FILENAME_SEPARATOR + PieceWise::MATHTYPE + FILE_EXT;
        out.open(name);
        k++;
    }
    auto piecewise_outs_Itr = piecewise_outs.begin();
    for(auto &core : singleCoreReadings){
        auto lines = PieceWise::linearly_interpolate(core);
        display<ofstream>(*piecewise_outs_Itr, lines, PieceWise::MATHTYPE);
        piecewise_outs_Itr->close();
        ++piecewise_outs_Itr;
    }


    //----LEAST SQUARES APPROXIMATION


    std::vector<ofstream> leastsqs_outs(singleCoreReadings.size());
    k = 0;
    for(auto &out : leastsqs_outs){
        std::string name = BASE_FILENAME + to_string(k) + 
                           FILENAME_SEPARATOR + LeastSquares::MATHTYPE + FILE_EXT;
        out.open(name);
        k++;
    }
    auto leastsqs_outs_Itr = leastsqs_outs.begin();
    for(auto const &core : singleCoreReadings){
        LineFormula line[] = {LeastSquares::approximate(core, 2)};
        
        display(*leastsqs_outs_Itr, line, LeastSquares::MATHTYPE);
        leastsqs_outs_Itr->close();
        ++leastsqs_outs_Itr;
    }
    


    return 0;
}
