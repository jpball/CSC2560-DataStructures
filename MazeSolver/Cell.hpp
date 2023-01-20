#pragma once

#include <string>

using namespace std;

class Cell{
public:
    Cell(char type);
    ~Cell();
    char getType();
    bool getIsVisited();
    void setVisited(bool value);
    char getMark();
    void setMark(char mark);
    Cell* getNorthCell();
    Cell* getEastCell();
    Cell* getSouthCell();
    Cell* getWestCell();
    void setNorth(Cell* p_North);
    void setEast(Cell* p_East);
    void setSouth(Cell* p_South);
    void setWest(Cell* p_West);
    
    int getXCoord();
    int getYCoord();
    
    void setXVal(int val);
    void setYVal(int val);
private:
    int x_coord;
    int y_coord;
    char cell_type;
    char cellMark;
    Cell* p_northCell;
    Cell* p_eastCell;
    Cell* p_southCell;
    Cell* p_westCell;
    bool isVisited;
    bool deadPath;
};
