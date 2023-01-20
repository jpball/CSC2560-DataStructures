#include <iostream>
#include <ctime>
#include "BoggleBoard.hpp"

using namespace std;

int main() {
    srand((unsigned int)time(0));
    cout << "Boggle Solver\n";
    BoggleBoard board("/Users/jordanball/DataStructures/BoggleSolver/Build/Products/Debug/bigDictionary.txt");
    board.printBoard();
    
    char choice;
    cout << "Would you like to see all possible values?\nY or N:";
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        board.solve();
        cout << "\nAll possible values: \n";
        board.printFoundWords();
    }
    cout << endl;
    return 0;
}
