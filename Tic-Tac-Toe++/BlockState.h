//
//  BlockState.h
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 7/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#ifndef BlockState_h
#define BlockState_h
#include <map>
#endif /* BlockState_h */
class BlockState{
public:
    enum State{
        EMPTY = 0,
        CROSS = 1,
        CIRCLE = 2
    };
    BlockState();
    BlockState(State state);
    State getState()const;
    bool isAssignableFrom(const BlockState &blockState) const;
    //todo wtf is a friend function
    friend std::ostream& operator<<(std::ostream& out, const BlockState value);
private:
    State state;
    static std::map<BlockState::State, char> stateOutputValues;
};

//should only do this for static. doing this for member/friend functions throws compiler error
static std::map<BlockState::State, char> stateOutputValues {
    {BlockState::State::EMPTY, '_'},
    {BlockState::State::CROSS, 'X'},
    {BlockState::State::CIRCLE, 'O'}
};

