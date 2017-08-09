//
//  Stroke.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 9/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include "Stroke.hpp"

    Stroke ::Stroke(int startPosition, int positionIncrement){
        blocks[0] = startPosition;
        blocks[1] = startPosition + positionIncrement;
        blocks[2] = startPosition + positionIncrement*2;
    }
    
    int Stroke::getFirst() const{
        return blocks[0];
    }
    
    int Stroke::getSecond() const{
        return blocks[1];
    }
    
    int Stroke::getThird() const{
        return blocks[2];
    }

    bool operator==(const Stroke &strokeA, const Stroke &strokeB) {
        return strokeA.getFirst() == strokeB.getFirst() && strokeA.getSecond() == strokeB.getSecond() && strokeA.getThird() == strokeB.getThird();
    }
