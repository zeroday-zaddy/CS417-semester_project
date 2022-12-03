#ifndef PROCESSOeR_INCLUDED
#define PROCESSOeR_INCLUDED

#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>
#include <vector>

#include "waltah_white_math.h"

/**
 * This represents a container of points
 * that make up the readings of a single core
 */
using SingleCoreTempReading = std::vector<Point>;

/**
 * Take a CoreTempReadingContainer and convert into a SingleCoreReadingContainer.
 *
 * @tparam CoreTempReadingContainer type of container to use (it must implement
 *     push_back and emplace_back)
 * @tparam SingleCoreReadingContainer type of container to use (it must implement
 *     push_back and emplace_back)
 *
 * @param byXreadings container made up of pairs of x value and container of y values  
 * @param byCoreReadings container made up of containers made up of pairs of x value and y value
 *
 * @return converted byCoreReadings
 */
template<typename CoreTempReadingContainer, typename SingleCoreReadingContainer>
void processByCore(const CoreTempReadingContainer&  byXreadings, 
                                            SingleCoreReadingContainer& byCoreReadings){
    //clear and return
    if(byXreadings.size() <= 0) {
        byCoreReadings.clear();
        return;
    }
    //grab amount of cores from first entry in byXreadings
    byCoreReadings.resize(byXreadings.begin()->second.size());
    
    //loop through byXreadings
    for(auto const &xToCores : byXreadings){
        //start at beginning of byCoreReadings
        auto byCoreItr = byCoreReadings.begin();

        //move through container of cores in xToCores.second
        for(auto const &yFromCores : xToCores.second){
            //create a point in current core 
            byCoreItr->emplace_back(xToCores.first, yFromCores);
            //move to next core in byCoreReadings
            ++byCoreItr;
        }
    }
}

#endif