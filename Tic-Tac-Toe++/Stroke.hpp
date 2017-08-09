//
//  Stroke.hpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 9/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#ifndef Stroke_hpp
#define Stroke_hpp

#endif /* Stroke_hpp */
class Stroke{
private:
    int blocks[3];
    //todo add block state for later implementation
public:
    Stroke(int startPosition, int positionIncrement);
    int getFirst()const;
    int getSecond()const;
    int getThird()const;
    friend bool operator==(const Stroke &strokeA,const Stroke &strokeB);
};
