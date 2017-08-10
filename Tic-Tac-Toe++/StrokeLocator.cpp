//
//  StrokeLocator.h
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 9/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include "StrokeLocator.h"


    bool StrokeLocator::isValidStroke(Stroke &stroke, const Grid &grid, const BlockState targetBlockState){
        return grid.getBlock(stroke.getFirst()).isAssignableFrom(targetBlockState)
        && grid.getBlock(stroke.getSecond()).isAssignableFrom(targetBlockState)
        && grid.getBlock(stroke.getThird()).isAssignableFrom(targetBlockState);
    }
    
    void StrokeLocator::addVerticalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState){
        for(int column = 0; column < Grid::STEP ; column ++){
            Stroke stroke = Stroke (column, Grid::STEP);
            if(isValidStroke(stroke, grid, targetBlockState)){
                strokes.push_back(stroke);
            }
        }
    }
    
    void StrokeLocator::addHorizontalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState){
        for(int row = 0; row < Grid::LIMIT ; row +=Grid::STEP){
            Stroke stroke = Stroke (row, 1);
            if(isValidStroke(stroke, grid, targetBlockState)){
                strokes.push_back(stroke);
            }
        }
    }
    
    void StrokeLocator::addDiagonalStrokes(std::vector<Stroke> &strokes,const Grid &grid, const BlockState targetBlockState){
        Stroke leftStroke = Stroke (0, 4);
        if(isValidStroke(leftStroke, grid, targetBlockState)){
            strokes.push_back(leftStroke);
        }
        
        Stroke rightStroke = Stroke (2, 2);
        if(isValidStroke(rightStroke , grid, targetBlockState)){
            strokes.push_back(rightStroke);
        }
    }

    std::vector<Stroke> StrokeLocator::findStrokes(const Grid &grid, const BlockState targetBlockState){
        std::vector<Stroke> strokes;
        addVerticalStrokes(strokes, grid, targetBlockState);
        addHorizontalStrokes(strokes, grid, targetBlockState);
        addDiagonalStrokes(strokes, grid, targetBlockState);
        strokes.erase(unique(strokes.begin(), strokes.end()), strokes.end()); //only take unique strokes -- maybe this is not required at all now !
        return strokes;
    }
