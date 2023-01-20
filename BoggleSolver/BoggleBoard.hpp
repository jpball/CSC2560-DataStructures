#pragma once

#include <string>
#include "BoggleDie.hpp"
#include "Trie.hpp"
#include "DoublyLinkedList.h"

using namespace std;

class BoggleBoard{
public:
    BoggleBoard(const string& pathToDictionary);
    ~BoggleBoard();

    void printBoard();
    void solve();
    
    void printFoundWords();
    
private:
    void solveHelper(const string& wordSoFar, int x, int y, DoublyLinkedList<string>& prevDiePositions);
    void shuffleDice();
    
    bool beenVisited(int x, int y, DoublyLinkedList<string>& prevPositions);
    
    Trie trie;
    BoggleDie** allDice;
    BoggleDie* board[5][5];
    DoublyLinkedList<string> wordsFound;
    
};
