//
//  main.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 7/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include <iostream>
#include <vector>
#include "StrokeLocator.cpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Grid grid;
    grid.print();
    grid.markIfEmpty(0, BlockState::CIRCLE);
    grid.print();

    std::vector<Stroke> strokes = StrokeLocator::findStrokes(grid, BlockState(BlockState::State::CROSS));
    
    //todo get best position to mark from probability evaluator
    //todo also factor in how many "moves" are required to complete a stroke
    grid.markIfEmpty(8, BlockState::CROSS);
    grid.print();
    return 0;
}
