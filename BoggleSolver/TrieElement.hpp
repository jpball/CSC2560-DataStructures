#pragma once

#include <string>
#include <iostream>

using namespace std;

class TrieElement{
public:
    TrieElement();
    ~TrieElement();
    void deleteHelper();
    void insertHelper(const string& word, string wordAdded);
    
    string searchHelper(const string& searchWord);
    void printHelper();
    
    bool hasChildren();
private:
    TrieElement* children[26];
    string wordSoFar;
    bool isCompleteWord;
};
