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
	//todo randomize start and symbols assigned to player vs AI
	//todo make this more expandable w.r.t grid size
	//todo make the AI configurable
    
    Grid grid;
    grid.print();

	const BlockState player = BlockState::CROSS;
	const BlockState ai = BlockState::CIRCLE;

    int input;
    while(true){
        std::cout<<"Enter position between 0-8 to make a move: ";
        std::cin>>input;
        if(input!=-1){
            grid.markIfEmpty(input, player);
            grid.print();
			if (StrokeLocator::isGameOver(input, grid)) {
				break;
			}
        } else {
            break;
        }
    
		std::vector<Stroke> aiStrokesWithLeastMoves = StrokeLocator::findStrokesWithLeastMoves(grid, ai);
		std::vector<Stroke> playerStrokesWithLeastMoves = StrokeLocator::findStrokesWithLeastMoves(grid, player);
		int blockToMark = ProbabilityLocator::extractMostProbableEmptyBlock(aiStrokesWithLeastMoves,playerStrokesWithLeastMoves, grid);
        if(blockToMark!=-1){
            grid.markIfEmpty(blockToMark, ai);
            grid.print();
			if (StrokeLocator::isGameOver(blockToMark, grid)) {
				break;
			}
        } else {
            break;
        }
    }
    std::cout<<"GAME OVER"<<std::endl<<"Enter any number to exit : ";
	std::cin >> input;
    return 0;
}
