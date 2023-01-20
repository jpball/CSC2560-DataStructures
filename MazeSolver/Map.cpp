#include "Map.hpp"

using namespace std;

Map::Map(string fileName){
    /*
     OPEN FILE AND READ IT
     */
    ifstream mapFILE;
    
    mapFILE.open(fileName);
    
    if(mapFILE.is_open()){
        char cellHold;
        int counter = 0;
        char temp;
        
        // Determine size of map
        while(!mapFILE.eof()){
            counter++;
            mapFILE >> temp;
        }
        
        this->numCells = counter - 1;
        dimension = sqrt(counter);
        
        p_allCells = new Cell*[this->numCells];

        mapFILE.close();
        
        // Reopen file to reset location
        mapFILE.open(fileName);
        
        if (mapFILE.is_open()) {
            // Read file and create cells
            for(int i = 0; i < this->numCells; i++){
                mapFILE >> cellHold;
                p_allCells[i] = new Cell(cellHold);
            }
            
            int xval = 0;
            int yval = 0;
            p_topLeft = p_allCells[0];
            
            for(int i = 0; i < this->numCells; i++){
                if(xval >= dimension){
                    xval = 0;
                    yval += 1;
                }
                
                p_allCells[i]->setXVal(xval);
                p_allCells[i]->setYVal(yval);
                
                
                // Checks to see if on the left edge
                if(i % dimension == 0){
                    p_allCells[i]->setWest(0);
                }
                else{
                    p_allCells[i]->setWest(p_allCells[i-1]);
                }
                
                // Checks to see if on the right edge
                if ((i + 1) % dimension == 0){
                    p_allCells[i]->setEast(0);
                }
                else{
                    p_allCells[i]->setEast(p_allCells[i+1]);
                }
                
                // Checks to see if on the top edge
                if(i < dimension){
                    p_allCells[i]->setNorth(0);
                }
                else{
                    p_allCells[i]->setNorth(p_allCells[i-dimension]);
                }
                
                // Checks to see if on the bottom edge
                if(i >= (this->numCells - dimension) && i < this->numCells){
                    p_allCells[i]->setSouth(0);
                }
                else{
                    p_allCells[i]->setSouth(p_allCells[i+dimension]);
                }
                
                if(p_allCells[i]->getType() == 'S'){
                    p_startingCell = p_allCells[i];
                    p_startingCell->setVisited(true);
                }
                xval++;
            }
        }
        else{
            cout << "ERROR: File could not be found!\n";
        }
        mapFILE.close();
    }
    else{
        cout << "ERROR: File could not be found!\n";
    }
}

Map::~Map(){
    for(int i = 0; i < this->numCells; i++){
        delete p_allCells[i];
        p_allCells[i] = 0;
    }
    delete [] p_allCells;
}

void Map::printCells(){
    cout << endl;
    for(int i = 0; i < this->numCells; i++){
        cout << p_allCells[i]->getType() << " ";
        if(((i + 1) % dimension) == 0){
            cout << endl;
        }
    }
}

void Map::printRoute(){
    cout << endl;
    for(int i = 0; i < this->numCells; i++){
        cout << p_allCells[i]->getMark() << " ";
        if(((i + 1) % dimension) == 0){
            cout << endl;
        }
    }
}

Cell* Map::getStartingCell(){
    return p_startingCell;
}

