#include "Cell.hpp"

Cell::Cell(char type){
    cell_type = type;
    isVisited = false;
    deadPath = false;
    cellMark = 'X';
}

Cell::~Cell(){
    p_northCell = 0;
    p_eastCell = 0;
    p_southCell = 0;
    p_westCell = 0;
}

void Cell::setMark(char mark){
    cellMark = mark;
}

char Cell::getMark(){
    return cellMark;
}

char Cell::getType(){
    return cell_type;
}

void Cell::setVisited(bool value){
    isVisited = value;
}

bool Cell::getIsVisited(){
    return isVisited;
}

void Cell::setNorth(Cell* p_North){
    p_northCell = p_North;
}

void Cell::setEast(Cell* p_East){
    p_eastCell = p_East;
}

void Cell::setSouth(Cell* p_South){
    p_southCell = p_South;
}

void Cell::setWest(Cell* p_West){
    p_westCell = p_West;
}

Cell* Cell::getNorthCell(){
    return p_northCell;
}

Cell* Cell::getEastCell(){
    return p_eastCell;
}

Cell* Cell::getSouthCell(){
    return p_southCell;
}

Cell* Cell::getWestCell(){
    return p_westCell;
}

int Cell::getXCoord(){
    return x_coord;
}

int Cell::getYCoord(){
    return y_coord;
}

void Cell::setXVal(int val){
    x_coord = val;
}

void Cell::setYVal(int val){
    y_coord = val;
}
