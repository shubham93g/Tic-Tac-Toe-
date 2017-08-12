//
//  ProbabilityLocator.hpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 10/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#ifndef ProbabilityLocator_hpp
#define ProbabilityLocator_hpp
#include <stdio.h>
#include <vector>
#include <map>
#include "StrokeLocator.h"
#include <iostream>

#endif /* ProbabilityLocator_hpp */

class ProbabilityLocator{
private:
    static void incrementBlockCount(int blockCounts[], const int blockPosition);
public:
    static int extractMostProbableBlock(std::vector<Stroke> &strokes, Grid &grid);
};
