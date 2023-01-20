#include "Map.hpp"
#include "Tracker.hpp"

#define THREE_THREE_MAP_PATH "3x3map.txt"
#define SIX_SIX_MAP_PATH "6x6map.txt"
#define TEN_TEN_MAP_PATH "10x10map.txt"

int main()
{
    //create a map from a file
    Map map(TEN_TEN_MAP_PATH);

    //create a tracker capable of traversing through a map
    Tracker tracker;

    //send the tracker to find a path through the map
    tracker.findPath(map);

    //print the original cells from the file
    map.printCells();

    //print an X/O map from the start to the end
    map.printRoute();

    return 0;
}