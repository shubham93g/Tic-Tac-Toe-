//
//  Grid.hpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 7/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include "BlockState.h"

#endif /* Grid_hpp */

// todo: WTF IS THIS ON TOP ? - getting back to C++ after ages..look for include guard ?

class Grid{
public:
    static const int LIMIT = 3;
    
    bool isValidAddress(const int positionX, const int positionY) const;
    void print() const;
    void markIfEmpty(const int positionX, const int positionY, const BlockState blockState);
    BlockState getState(const int positionX, const int positionY) const;
    Grid();
private:
    void setUncheckedState(const int positionX, const int positionY, const BlockState blockState);
    BlockState getUncheckedState(const int positionX, const int positionY) const;
    BlockState playingGrid[LIMIT][LIMIT];
};
