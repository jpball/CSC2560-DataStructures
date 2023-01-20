#include "Tracker.hpp"

void Tracker::findPath(Map& map){
    p_current = map.getStartingCell();
    visitedCells.push(p_current);
    while(p_current->getType() != 'E'){
        move();
    }
    visitedCells.push(p_current);
    
    while(visitedCells.size() > 0){
        Cell* poppedCell = visitedCells.pop();
        poppedCell->setMark('O');
    }
}

void Tracker::move(){
    p_current->setVisited(true);
    if(p_current->getNorthCell() &&
       (p_current->getNorthCell()->getType() == 'F' || p_current->getNorthCell()->getType() == 'E') &&
        p_current->getNorthCell()->getIsVisited() == false)
    {
        visitedCells.push(p_current);
        p_current = p_current->getNorthCell();
        p_current->setVisited(true);
        cout << "Going North " << "X: " << p_current->getXCoord() << " Y: " << p_current->getYCoord() << " Type: " << p_current->getType() << endl;
    }
    else if (p_current->getEastCell() &&
             (p_current->getEastCell()->getType() == 'F' || p_current->getEastCell()->getType() == 'E')
             && p_current->getEastCell()->getIsVisited() == false)
    {
        visitedCells.push(p_current);
        p_current = p_current->getEastCell();
        p_current->setVisited(true);
        
        cout << "Going East " << "X: " << p_current->getXCoord() << " Y: " << p_current->getYCoord() << " Type: " << p_current->getType() << endl;
    }
    
    else if (p_current->getSouthCell() &&
             (p_current->getSouthCell()->getType() == 'F' || p_current->getSouthCell()->getType() == 'E') &&
             p_current->getSouthCell()->getIsVisited() == false)
    {
        visitedCells.push(p_current);
        p_current = p_current->getSouthCell();
        p_current->setVisited(true);

        cout << "Going South " << "X: " << p_current->getXCoord() << " Y: " << p_current->getYCoord() << " Type: " << p_current->getType() << endl;
    }
    
    else if (p_current->getWestCell() &&
             (p_current->getWestCell()->getType() == 'F' || p_current->getWestCell()->getType() == 'E') &&
             p_current->getWestCell()->getIsVisited() == false){
        visitedCells.push(p_current);
        p_current = p_current->getWestCell();
        p_current->setVisited(true);

        cout << "Going West " << "X: " << p_current->getXCoord() << " Y: " << p_current->getYCoord() << " Type: " << p_current->getType() << endl;
    }
    
    // Backtrack
    else{
        cout << "Backtracking from: " << "X: " << p_current->getXCoord() << " Y: " << p_current->getYCoord() << " Type: " << p_current->getType();
        
        p_current = visitedCells.pop();
        
        cout << " to X: " << p_current->getXCoord() << " Y: " << p_current->getYCoord() << " Type: " << p_current->getType() << endl;
        move();
    }
    
}
