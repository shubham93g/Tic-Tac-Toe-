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
BlockState Grid::getUncheckedState(const int position) const{
    return playingGrid[position];
}

void Grid::setUncheckedState(const int position,const BlockState blockState){
    playingGrid[position] = blockState;
}

//public

bool Grid::isValidAddress(int position) const{
    return position < LIMIT;
}

Grid::Grid(){
    //initialise empty grid
    for(int i=0;i<LIMIT;i++){
            setUncheckedState(i, BlockState::EMPTY);
        }
}

BlockState Grid::getState(const int position) const{
    if(isValidAddress(position)){
        return getUncheckedState(position);
    }
    //throw exception ?
    return BlockState::EMPTY;
}

void Grid::markIfEmpty(const int position, const BlockState blockState){
    if(getState(position)==BlockState::EMPTY){
        setUncheckedState(position,blockState);
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
    for(int i=0;i<LIMIT;i+=STEP){
        for(int j=0;j<STEP;j++){
            std::cout<<getUncheckedState(i + j);
        }
        std::cout<<"\n";
    }
}
