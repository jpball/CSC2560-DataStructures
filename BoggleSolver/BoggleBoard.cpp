#include "BoggleBoard.hpp"


BoggleBoard::BoggleBoard(const string& pathToDictionary)
: trie(pathToDictionary){
    const static string diceCombos[25][6] = {{ "N", "S", "C", "T", "E", "C" },
    { "A", "E", "A", "E", "E", "E" },
    { "H", "H", "L", "R", "O", "D" },
    { "O", "R", "W", "V", "G", "R" },
    { "S", "P", "R", "I", "Y", "Y" },
    { "S", "U", "E", "N", "S", "S" },
    { "M", "E", "A", "U", "E", "G" },
    { "S", "E", "P", "T", "I", "C" },
    { "D", "H", "H", "O", "W", "N" },
    { "L", "E", "P", "T", "I", "S" },
    { "S", "T", "L", "I", "E", "I" },
    { "A", "R", "S", "I", "Y", "F" },
    { "T", "E", "T", "I", "I", "I" },
    { "O", "T", "T", "T", "M", "E" },
    { "N", "M", "N", "E", "G", "A" },
    { "N", "N", "E", "N", "A", "D" },
    { "O", "U", "O", "T", "T", "O" },
    { "B", "Z", "J", "B", "X", "K" },
    { "A", "A", "F", "A", "S", "R" },
    { "T", "O", "O", "U", "W", "N" },
    { "O", "T", "H", "D", "D", "N" },
    { "R", "A", "A", "S", "F", "I" },
    { "H", "O", "D", "R", "L", "N" },
    { "E", "E", "E", "E", "A", "M" },
        { "He", "Qu", "Th", "In", "Er", "An" }};
    
    // Create array of Dice on Heap
    allDice = new BoggleDie*[25];
    
    // Create Boggle Die in array allDice
    for(int i = 0; i < 25; i++){
        allDice[i] = new BoggleDie(diceCombos[i]);
    }
    
    shuffleDice();
    
    // Add these die to the board 2D array
    int pos = 0;
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 5; col++){
            board[row][col] = allDice[pos];
            pos++;
        }
    }
}

BoggleBoard::~BoggleBoard(){
    // Delete all die in array
    for(int i = 0; i < 25; i++){
        delete allDice[i];
    }
    delete [] allDice;
}

void BoggleBoard::shuffleDice(){
    for(int i = 0; i < 25; i++){
        BoggleDie* p_temp = allDice[i];
        int randPos = rand() % 25;
        
        allDice[i] = allDice[randPos];
        allDice[randPos] = p_temp;
    }
    cout << "Dice shuffled!\n";
}

void BoggleBoard::printBoard(){
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 5; col++){
            cout << board[row][col]->getRolledValue() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void BoggleBoard::solve(){
    for(int row = 0; row < 5; row++){
        for(int col = 0; col < 5; col++){
            DoublyLinkedList<string> prevDiePositions;
            solveHelper("", row, col, prevDiePositions);
        }
    }
}

void BoggleBoard::solveHelper(const string& wordSoFar, int x, int y, DoublyLinkedList<string>& prevDiePositions){
    if(x < 0 || x >= 5 || y < 0 || y >= 5 || beenVisited(x, y, prevDiePositions) || (trie.search(wordSoFar) == "NOT FOUND")){
        return;
    }
    else{
        string currPosition = to_string(x) + ":" + to_string(y);
        prevDiePositions.insertAtFront(currPosition);
        
        string newWord = wordSoFar + board[x][y]->getRolledValue();
        if(trie.search(newWord) == "FOUND"){
            // If found, add word to list
            if(newWord.size() >= 4){
                if(!wordsFound.find(newWord)){
                    wordsFound.insertAtFront(newWord);
                }
            }
        }
        solveHelper(newWord, x-1, y-1, prevDiePositions);
        solveHelper(newWord, x, y-1, prevDiePositions);
        solveHelper(newWord, x+1, y-1, prevDiePositions);
        solveHelper(newWord, x-1, y, prevDiePositions);
        solveHelper(newWord, x+1, y, prevDiePositions);
        solveHelper(newWord, x-1, y+1, prevDiePositions);
        solveHelper(newWord, x, y+1, prevDiePositions);
        solveHelper(newWord, x+1, y+1, prevDiePositions);
    }
}

bool BoggleBoard::beenVisited(int x, int y, DoublyLinkedList<string>& prevPositions){
    string currPos = to_string(x) + ":" + to_string(y);
    string elem;
    
    prevPositions.first(elem);
    do{
        if(elem == currPos){
            return true;
        }
    }while(prevPositions.next(elem));
    
    return false;
}


void BoggleBoard::printFoundWords(){
    string word;
    cout << wordsFound.size() << " words found!\n";
    wordsFound.first(word);
    do{
        cout << word << endl;
    }while(wordsFound.next(word));
}
