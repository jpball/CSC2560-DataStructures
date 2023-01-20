#pragma once

#include "TrieElement.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Trie{
public:
    Trie(const string& filepath);
    ~Trie();
    string search(const string& word);
    void printAllWords();
private:
    string lowercase(string word);
    void insert(const string& word);
    TrieElement* root;
    unsigned int numWords;
};
