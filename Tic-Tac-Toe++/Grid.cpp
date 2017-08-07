//
//  Grid.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 7/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include "Grid.hpp"
#include <iostream>

//private
BlockState Grid::getUncheckedState(const int positionX,const int positionY) const{
    return playingGrid[positionX][positionY];
}

void Grid::setUncheckedState(const int positionX,const int positionY,const BlockState blockState){
    playingGrid[positionX][positionY] = blockState;
}

//public

bool Grid::isValidAddress(int positionX, int positionY) const{
    return positionX < Grid::LIMIT && positionY < Grid::LIMIT;
}

Grid::Grid(){
    //initialise empty grid
    for(int i=0;i<Grid::LIMIT;i++)
        for(int j=0;j<Grid::LIMIT;j++){
            setUncheckedState(i, j, BlockState::EMPTY);
        }
}

BlockState Grid::getState(const int positionX, const int positionY) const{
    if(isValidAddress(positionX, positionY)){
        return getUncheckedState(positionX, positionY);
    }
    //throw exception ?
    return BlockState::EMPTY;
}

void Grid::markIfEmpty(const int positionX, const int positionY,const BlockState blockState){
    if(getState(positionX,positionY)==BlockState::EMPTY){
        setUncheckedState(positionX,positionY,blockState);
    }
    //throw exception ?
}

std::ostream& operator<<(std::ostream& out, const BlockState value){
    static std::map<BlockState, std::string> strings {
        {BlockState::EMPTY, "_"},
        {BlockState::CROSS, "X"},
        {BlockState::CIRCLE, "O"}
    };
    
    return out << strings[value];
}

void Grid::print() const{
    std::cout<<"\n";
    for(int i=0;i<Grid::LIMIT;i++){
        for(int j=0;j<Grid::LIMIT;j++){
            std::cout<<getUncheckedState(i, j);
        }
        std::cout<<"\n";
    }
}
