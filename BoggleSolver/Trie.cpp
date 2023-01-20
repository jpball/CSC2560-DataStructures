#include "Trie.hpp"


Trie::Trie(const string& dictPath){
    cout << "Loading trie...\n";
    root = new TrieElement;
    
    ifstream dictFILE;
    dictFILE.open(dictPath);
    
    string readWord;
    dictFILE >> readWord;
    
    while(dictFILE.good()){
        root->insertHelper(lowercase(readWord), "");
        
        dictFILE >> readWord;
    }
    cout << "Trie loaded! There were " << numWords << " words added.\n";

    dictFILE.close();
}

Trie::~Trie(){
    delete root;
}

string Trie::lowercase(string word){
    string newWord = "";
    for(int i = 0; i < word.size(); i++){
        newWord += tolower(word.at(i));
    }
    return newWord;
}


void Trie::insert(const string& word){
    root->insertHelper(lowercase(word), "");
    numWords++;
}

string Trie::search(const string& searchWord){
    return root->searchHelper(lowercase(searchWord));
}

void Trie::printAllWords(){
    root->printHelper();
}

