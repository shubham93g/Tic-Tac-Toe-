//
//  ProbabilityLocator.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 10/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include "ProbabilityLocator.hpp"

 void ProbabilityLocator::incrementBlockCount(int blockCounts[], const int blockPosition){
    int count = blockCounts[blockPosition];
    blockCounts[blockPosition] = ++count;
}

int ProbabilityLocator::extractMostProbableBlock(std::vector<Stroke> &strokes, Grid &grid){
    
    if(strokes.size()==0){
        return -1;
    }
    
    int blockCounts[9] = {0,0,0,0,0,0,0,0};
    
    for(std::vector<Stroke>::iterator stroke = strokes.begin(); stroke < strokes.end(); stroke ++){
        if(grid.getBlock(stroke->getFirst()).getState() == BlockState::EMPTY){
            incrementBlockCount(blockCounts, stroke->getFirst());
        }
        if(grid.getBlock(stroke->getSecond()).getState() == BlockState::EMPTY){
            incrementBlockCount(blockCounts, stroke->getSecond());
        }
        if(grid.getBlock(stroke->getThird()).getState() == BlockState::EMPTY){
            incrementBlockCount(blockCounts, stroke->getThird());
        }
    }
    
    int mostProbable = 0;
    for(int position = 0; position < 9; position++){
        if(blockCounts[position] > blockCounts[mostProbable]){
            mostProbable = position;
        }
    }
    
    return mostProbable;
}
