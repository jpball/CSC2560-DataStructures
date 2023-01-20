#include "TrieElement.hpp"

TrieElement::TrieElement(){
    for(int i = 0; i < 26; i++){
        children[i] = NULL;
    }
    wordSoFar = "";
    isCompleteWord = false;
}

TrieElement::~TrieElement(){
    for(int i = 0; i < 26; i++){
        if(children[i] != NULL){
            delete children[i];
            children[i] = NULL;
        }
    }
}

 void TrieElement::insertHelper(const string& word, string wordAdded){
     wordSoFar = wordAdded;
     // BASE CASE (word fully input)
     if(word.size() == 0){
         isCompleteWord = true;
     }
     
     // GENERAL CASE (Recurse to keep making children)
     else{
         unsigned int childIndex = word.at(0) - 'a';
         // Checks if a child is already created
         // Creates one if NOT
         if( children[childIndex] == NULL ){
             children[childIndex] = new TrieElement;
         }
         wordAdded.push_back(word.at(0));
         children[childIndex]->insertHelper(word.substr(1, string::npos), wordAdded);
     }
 }

string TrieElement::searchHelper(const string& searchWord){
    if(isCompleteWord && searchWord.length() == 0){
        return "FOUND";
    }
    else if (searchWord.length() == 0){
        return "PARTIAL";
    }
    else if(!hasChildren() && searchWord.length() > 0){
        return "NOT FOUND";
    }
    else{
        if(children[searchWord.at(0) - 'a'] != NULL){
            return children[searchWord.at(0) - 'a']->searchHelper(searchWord.substr(1, string::npos));
        }
        else{
            return "NOT FOUND";
        }
    }
}

bool TrieElement::hasChildren(){
    bool retVal = false;
    for(int i = 0; i < 26; i++){
        if(children[i] != 0){
            retVal = true;
            break;
        }
    }
    return retVal;
}

void TrieElement::printHelper(){
    if(isCompleteWord){
        cout << wordSoFar << endl;
    }
    for(int i = 0; i < 26; i++){
        if(children[i] != 0){
            children[i]->printHelper();
        }
    }
}
