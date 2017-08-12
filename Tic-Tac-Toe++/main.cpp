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
    //todo factor in opponent probability
    //todo figure end game winner and better game end condition
    
    Grid grid;
    grid.print();

    std::vector<Stroke> strokes;
    int blockToMark;
    int input;
    
    while(true){
        std::cout<<"Enter position to make a move: ";
        std::cin>>input;
        if(input!=-1){
            grid.markIfEmpty(input, BlockState::CROSS);
            grid.print();
        } else {
            break;
        }
    
        strokes = StrokeLocator::findStrokesWithLeastMoves(grid, BlockState(BlockState::CIRCLE));
        blockToMark = ProbabilityLocator::extractMostProbableBlock(strokes, grid);
        if(blockToMark!=-1){
            grid.markIfEmpty(blockToMark, BlockState::CIRCLE);
            grid.print();
        } else {
            break;
        }
    }
    std::cout<<"GAME OVER"<<std::endl;
    return 0;
}
