//
//  StrokeLocator.h
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 10/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#ifndef StrokeLocator_h
#define StrokeLocator_h
#include "Grid.hpp"
#include "Stroke.hpp"
#include <vector>
#endif /* StrokeLocator_h */

class StrokeLocator{
private:
	static bool assertGameOverCondition(const int startPosition, const int positionIncrement, const Grid &grid);
    static bool isValidStroke(const Stroke &stroke, const Grid &grid, const BlockState targetBlockState);
	static void calculateMovesToCompleteStroke(Stroke &stroke, const Grid &grid, const BlockState targetBlockState);
    static void addVerticalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState);
    static void addHorizontalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState);
    static void addDiagonalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState);
    static std::vector<Stroke> getStrokesWithLeastMoves(std::vector<Stroke> &strokes);
public:
	static bool isGameOver(const int lastBlockMarked, const Grid &grid);
    static std::vector<Stroke> findStrokesWithLeastMoves(const Grid &grid, const BlockState targetBlockState);
};
