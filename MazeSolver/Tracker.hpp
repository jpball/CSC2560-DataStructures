#pragma once

#include "Map.hpp"
#include "Cell.hpp"
#include "Stack.h"

class Tracker{
public:
    void findPath(Map& map);
private:
    void move();
    Cell* p_current;
    Stack<Cell*> visitedCells;
};
