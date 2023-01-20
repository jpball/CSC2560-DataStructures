#include "BoggleDie.hpp"

BoggleDie::BoggleDie(const string faceCombos[6]){
    rolledValue = faceCombos[rand() % 6];
}

string BoggleDie::getRolledValue(){
    return rolledValue;
}
