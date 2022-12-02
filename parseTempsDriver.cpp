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
#include "DataDisplayer.h"

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

    std::vector<ofstream> outs(readings.begin()->second.size());
    int k = 0;
    for(auto &out : outs){
        std::string name = BASE_FILENAME + to_string(k) + 
                           FILENAME_SEPARATOR + PieceWise::MATHTYPE + FILE_EXT;
        out.open(name);
        k++;
    }


    display(outs, readings);


    std::vector<std::vector<Point>> singleCoreReadings;
    arrangeByCore<std::vector<CoreTempReading>, std::vector<vector<Point>>>(readings, singleCoreReadings);

    
    for(auto &out : outs){
        out.close();
    }


    return 0;
}
