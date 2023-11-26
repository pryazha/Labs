#pragma once

#include "minterms.h"

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Minimizer
{
public:
    bool IsValid(string& str);
    vector<mintermGroup> StringToMintermGroups(const string& str);
    bool PrintGroups(const vector<mintermGroup>& minterms);
};
