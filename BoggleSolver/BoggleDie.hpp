#pragma once

#include <string>
#include <iostream>

using namespace std;

class BoggleDie{
public:
    BoggleDie(const string faceCombos[6]);
    string getRolledValue();
private:
    string rolledValue;
};
