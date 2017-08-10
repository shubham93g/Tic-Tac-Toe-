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

//
//  StrokeLocator.h
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 9/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

class StrokeLocator{
private:
    
    static bool isValidStroke(Stroke &stroke, const Grid &grid, const BlockState targetBlockState);
    static void addVerticalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState);
    static void addHorizontalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState);
    static void addDiagonalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState);
public:
    static std::vector<Stroke> findStrokes(const Grid &grid, const BlockState targetBlockState);
};
