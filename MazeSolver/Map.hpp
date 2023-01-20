#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Cell.hpp"
#include <math.h>

using namespace std;

class Map{
public:
    Map(string fileName); // Read file to get # of cells and dimension (sqrt(total) = dimension
    ~Map();
    void printCells();
    void printRoute();
    Cell* getStartingCell();
private:
    Cell** p_allCells;
    Cell* p_startingCell;
    Cell* p_topLeft;
    int numCells;
    int dimension;
    
};
