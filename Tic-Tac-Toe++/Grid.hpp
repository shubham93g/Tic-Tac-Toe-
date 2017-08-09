//
//  Grid.hpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 7/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include "BlockState.h"

#endif /* Grid_hpp */

// todo: WTF IS THIS ON TOP ? - getting back to C++ after ages..look for include guard ?

class Grid{
public:
    static const int LIMIT = 9;
    static const int STEP = 3;
    
    bool isValidAddress(const int position) const;
    void print() const;
    void markIfEmpty(const int position, const BlockState blockState);
    BlockState getBlock(const int position) const;
    Grid();
private:
    void setUncheckedState(const int position, const BlockState blockState);
    BlockState getUncheckedState(const int position) const;
    BlockState playingGrid[LIMIT];
};
