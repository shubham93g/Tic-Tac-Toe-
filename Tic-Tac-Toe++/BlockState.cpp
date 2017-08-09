//
//  BlockState.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 9/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include "BlockState.h"
#include <iostream>

BlockState::State BlockState::getState()const{
    return state;
}

BlockState::BlockState(BlockState::State state){
    this->state = state;
}

BlockState::BlockState(){
    this->state = State::EMPTY;
}

std::ostream& operator<<(std::ostream& out, const BlockState value){
    return out << stateOutputValues[value.getState()];
}

bool BlockState::isAssignableFrom(const BlockState &blockState) const {
    return this->state == State::EMPTY || blockState.getState() == this->state;
}
