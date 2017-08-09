//
//  main.cpp
//  Tic-Tac-Toe++
//
//  Created by Shubham Goyal on 7/8/17.
//  Copyright © 2017 Shubham Goyal. All rights reserved.
//

#include <iostream>
#include <set>
#include "Grid.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Grid grid;
    grid.print();
    grid.markIfEmpty(0, BlockState::CIRCLE);
    grid.print();
    grid.markIfEmpty(8, BlockState::CROSS);
    grid.print();
    return 0;
}

void testingFunction(){
    typedef std::pair<int, int> Point; //or could I use a different identifier ?
    //todo need a structure to hold 3 Points in any sequence - might be easier to store a sequence
    typedef std::set<Point> List; //needs to be a set of the structure having 3 points
    //todo a map to count the number of 3 point structures
}
