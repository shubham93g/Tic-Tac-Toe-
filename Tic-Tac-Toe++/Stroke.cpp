//
//  Stroke.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 9/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include "Stroke.hpp"

    Stroke ::Stroke(int startPosition, int positionIncrement){
        blockPositionsOnGrid[0] = startPosition;
        blockPositionsOnGrid[1] = startPosition + positionIncrement;
        blockPositionsOnGrid[2] = startPosition + positionIncrement*2;
        movesRequired = 3; // default value
    }
    
    int Stroke::getFirst() const{
        return blockPositionsOnGrid[0];
    }
    
    int Stroke::getSecond() const{
        return blockPositionsOnGrid[1];
    }
    
    int Stroke::getThird() const{
        return blockPositionsOnGrid[2];
    }

    int Stroke::getMovesRequired()const{
        return movesRequired;
    }

    void Stroke::setMovesRequired(const int moves){
        movesRequired = moves;
    }

    bool operator==(const Stroke &strokeA, const Stroke &strokeB) {
        return strokeA.getFirst() == strokeB.getFirst() && strokeA.getSecond() == strokeB.getSecond() && strokeA.getThird() == strokeB.getThird();
    }
