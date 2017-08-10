//
//  ProbabilityLocator.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 10/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include "ProbabilityLocator.hpp"

 void ProbabilityLocator::incrementBlockCount(std::map<int,int> &blockCounts, const int blockPosition){
    std::map<int, int>::iterator block = blockCounts.find(blockPosition);
    int value = block->second;
    block->second = ++value;
}

//todo I could very simply just place an array here..sigh
//i made this so complicated..
//lesson learnt - think simple
int ProbabilityLocator::extractMostProbableBlock(std::vector<Stroke> &strokes, Grid &grid){
    std::map<int,int> blockCounts {
        {0,0},
        {1,0},
        {2,0},
        {3,0},
        {4,0},
        {5,0},
        {6,0},
        {7,0},
        {8,0}
    };
    
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
    
    std::map<int, int>::iterator mostProbable = blockCounts.begin();
    for(std::map<int, int>::iterator block = blockCounts.begin(); block != blockCounts.end(); block ++){
        if(block->second > mostProbable->second){
            mostProbable = block;
        }
    }
    
    return mostProbable->first;
}
