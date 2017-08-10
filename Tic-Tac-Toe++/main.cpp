//
//  main.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 7/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include <iostream>
#include <vector>
#include "ProbabilityLocator.hpp"

int main(int argc, const char * argv[]) {
    //todo also factor in how many "moves" are required to complete a stroke
    //todo factor in opponent probability
    //todo figure end game condition
    
    Grid grid;
    grid.markIfEmpty(6, BlockState::CIRCLE);
    grid.print();

    std::vector<Stroke> strokes = StrokeLocator::findStrokes(grid, BlockState(BlockState::CROSS));
    int blockToMark = ProbabilityLocator::extractMostProbableBlock(strokes, grid);
    grid.markIfEmpty(blockToMark, BlockState::CROSS);
    grid.print();
    
    strokes = StrokeLocator::findStrokes(grid, BlockState(BlockState::CIRCLE));
    blockToMark = ProbabilityLocator::extractMostProbableBlock(strokes, grid);
    grid.markIfEmpty(blockToMark, BlockState::CIRCLE);
    grid.print();
    
    strokes = StrokeLocator::findStrokes(grid, BlockState(BlockState::CROSS));
    blockToMark = ProbabilityLocator::extractMostProbableBlock(strokes, grid);
    grid.markIfEmpty(blockToMark, BlockState::CROSS);
    grid.print();
    
    strokes = StrokeLocator::findStrokes(grid, BlockState(BlockState::CIRCLE));
    blockToMark = ProbabilityLocator::extractMostProbableBlock(strokes, grid);
    grid.markIfEmpty(blockToMark, BlockState::CIRCLE);
    grid.print();
    
    strokes = StrokeLocator::findStrokes(grid, BlockState(BlockState::CROSS));
    blockToMark = ProbabilityLocator::extractMostProbableBlock(strokes, grid);
    grid.markIfEmpty(blockToMark, BlockState::CROSS);
    grid.print();
    
    strokes = StrokeLocator::findStrokes(grid, BlockState(BlockState::State::CIRCLE));
    blockToMark = ProbabilityLocator::extractMostProbableBlock(strokes, grid);
    grid.markIfEmpty(blockToMark, BlockState::CIRCLE);
    grid.print();
    return 0;
}
