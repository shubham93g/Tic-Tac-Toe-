//
//  StrokeLocator.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 9/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include "StrokeLocator.h"

bool StrokeLocator::assertGameOverCondition(const int startPosition, const int positionIncrement, const Grid & grid){
	return grid.getBlock(startPosition).getState() == grid.getBlock(startPosition + positionIncrement).getState() &&
		grid.getBlock(startPosition).getState() == grid.getBlock(startPosition + positionIncrement * 2).getState() &&
		grid.getBlock(startPosition).getState() != BlockState::EMPTY;
}

bool StrokeLocator::isValidStroke(const Stroke &stroke, const Grid &grid, const BlockState targetBlockState){
        return grid.getBlock(stroke.getFirst()).isAssignableFrom(targetBlockState)
        && grid.getBlock(stroke.getSecond()).isAssignableFrom(targetBlockState)
        && grid.getBlock(stroke.getThird()).isAssignableFrom(targetBlockState);
    }

	void StrokeLocator::calculateMovesToCompleteStroke(Stroke &stroke, const Grid &grid, const BlockState targetBlockState) {
		int movesRequired = 0;
		if (grid.getBlock(stroke.getFirst()).getState() == BlockState::EMPTY) {
			movesRequired++;
		}
		if (grid.getBlock(stroke.getSecond()).getState() == BlockState::EMPTY) {
			movesRequired++;
		}
		if (grid.getBlock(stroke.getThird()).getState() == BlockState::EMPTY) {
			movesRequired++;
		}
		stroke.setMovesRequired(movesRequired);
	}
    
    void StrokeLocator::addVerticalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState){
        for(int column = 0; column < Grid::STEP ; column ++){
            Stroke stroke = Stroke (column, Grid::STEP);
            if(isValidStroke(stroke, grid, targetBlockState)){
				calculateMovesToCompleteStroke(stroke, grid, targetBlockState);
                strokes.push_back(stroke);
            }
        }
    }
    
    void StrokeLocator::addHorizontalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState){
        for(int row = 0; row < Grid::LIMIT ; row +=Grid::STEP){
            Stroke stroke = Stroke (row, 1);
            if(isValidStroke(stroke, grid, targetBlockState)){
				calculateMovesToCompleteStroke(stroke, grid, targetBlockState);
                strokes.push_back(stroke);
            }
        }
    }
    
    void StrokeLocator::addDiagonalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState){
        Stroke leftDiagonal = Stroke (0, 4);
        if(isValidStroke(leftDiagonal, grid, targetBlockState)){
			calculateMovesToCompleteStroke(leftDiagonal, grid, targetBlockState);
            strokes.push_back(leftDiagonal);
        }
        
        Stroke rightDiagonal = Stroke (2, 2);
        if(isValidStroke(rightDiagonal , grid, targetBlockState)){
			calculateMovesToCompleteStroke(rightDiagonal, grid, targetBlockState);
            strokes.push_back(rightDiagonal);
        }
    }

    std::vector<Stroke> StrokeLocator::getStrokesWithLeastMoves(std::vector<Stroke> &strokes){
        std::vector<Stroke> oneMoves, twoMoves, threeMoves;
        for(std::vector<Stroke>::iterator stroke = strokes.begin(); stroke < strokes.end(); stroke ++){
            if(stroke->getMovesRequired()==1){
                oneMoves.push_back(*stroke);
            }
            if(stroke->getMovesRequired()==2){
                twoMoves.push_back(*stroke);
            }
            if(stroke->getMovesRequired()==3){
                threeMoves.push_back(*stroke);
            }
        }
        
        if(oneMoves.size()!=0){
            return oneMoves;
        }
        if(twoMoves.size()!=0){
            return twoMoves;
        }
        return threeMoves;
    }

	//todo is there a better way instead of the ugly hardcoding ?
	bool StrokeLocator::isGameOver(const int lastBlockMarked, const Grid & grid){
		const bool row0 = assertGameOverCondition(0, 1, grid);
		const bool row1 = assertGameOverCondition(3, 1, grid);
		const bool row2 = assertGameOverCondition(6, 1, grid);
		const bool col0 = assertGameOverCondition(0, 3, grid);
		const bool col1 = assertGameOverCondition(1, 3, grid);
		const bool col2 = assertGameOverCondition(2, 3, grid);
		const bool leftDiag = assertGameOverCondition(0, 4, grid);
		const bool rightDiag = assertGameOverCondition(2, 2, grid);
		switch (lastBlockMarked) {
			case 0: return row0 || col0 || leftDiag;
			case 1: return row0 || col1;
			case 2: return row0 || col2 || rightDiag;
			case 3: return row1 || col0;
			case 4: return row1 || col1 || leftDiag || rightDiag;
			case 5: return row1 || col2;
			case 6: return row2 || col0 || rightDiag;
			case 7: return row2 || col1;
			case 8: return row2 || col2 || leftDiag;
			default: return false;
		}
	}

	std::vector<Stroke> StrokeLocator::findStrokesWithLeastMoves(const Grid &grid, const BlockState targetBlockState){
        std::vector<Stroke> allPossibleStrokes;
        addVerticalStrokes(allPossibleStrokes, grid, targetBlockState);
        addHorizontalStrokes(allPossibleStrokes, grid, targetBlockState);
        addDiagonalStrokes(allPossibleStrokes, grid, targetBlockState);
        return getStrokesWithLeastMoves(allPossibleStrokes);

    }
