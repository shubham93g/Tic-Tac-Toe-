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

 int ProbabilityLocator::extractMostProbableEmptyBlock(std::vector<Stroke> &strokesWithMinMoves, const Grid &grid) {
	 int strokesPossibleOnBlock[9] = { 0,0,0,0,0,0,0,0 };
	 for (std::vector<Stroke>::iterator stroke = strokesWithMinMoves.begin(); stroke < strokesWithMinMoves.end(); stroke++) {
		 if (grid.getBlock(stroke->getFirst()).getState() == BlockState::EMPTY) {
			 incrementBlockCount(strokesPossibleOnBlock, stroke->getFirst());
		 }
		 if (grid.getBlock(stroke->getSecond()).getState() == BlockState::EMPTY) {
			 incrementBlockCount(strokesPossibleOnBlock, stroke->getSecond());
		 }
		 if (grid.getBlock(stroke->getThird()).getState() == BlockState::EMPTY) {
			 incrementBlockCount(strokesPossibleOnBlock, stroke->getThird());
		 }
	 }

	 //find and return most probably empty block
	 int mostProbableEmptyBlock = 0;
	 for (int position = 0; position < 9; position++) {
		 if (strokesPossibleOnBlock[position] > strokesPossibleOnBlock[mostProbableEmptyBlock]) {
			 mostProbableEmptyBlock = position;
		 }
	 }
	 return mostProbableEmptyBlock;
}

int ProbabilityLocator::extractMostProbableEmptyBlock(std::vector<Stroke> &aiStrokesWithMinMoves, std::vector<Stroke> &playerStrokesWithMinMoves, const Grid &grid){
    
    if(aiStrokesWithMinMoves.size()==0){
        return -1;
    }

	if (playerStrokesWithMinMoves.size() != 0 && playerStrokesWithMinMoves.front().getMovesRequired() == 1 & aiStrokesWithMinMoves.front().getMovesRequired() > 1) {
		//block the most probable player block to prevent loss
		return extractMostProbableEmptyBlock(playerStrokesWithMinMoves, grid);
	}
	else {
		//get the most probable ai block for win
		return extractMostProbableEmptyBlock(aiStrokesWithMinMoves, grid);
	}
}
