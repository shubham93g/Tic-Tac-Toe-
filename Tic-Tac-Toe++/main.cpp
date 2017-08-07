//
//  main.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 7/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include <iostream>
#include "Grid.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Grid grid;
    grid.print();
    grid.markIfEmpty(0, 0, BlockState::CIRCLE);
    grid.print();
    grid.markIfEmpty(2,2, BlockState::CROSS);
    grid.print();
    return 0;
}
