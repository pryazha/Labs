#pragma once

#include "conjunction.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using std::vector;
using std::string;
using std::left;
using std::setw;

class QuineMinimization
{
public:
    bool IsValid(string& str);

    void StringToConjunctions(const string& str);

    void PrintMatrix(const string& str);
    void PrintConjunctions(vector<conjunction> conjunctions);
    void PrintCoverageTable(vector<conjunction> implicants);

    bool partOfConjunction(conjunction con1, conjunction con2);
    vector<conjunction> GetImplicants();
    void deleteDublicates(vector<conjunction>& conjunctions);
    bool canBeCombined(conjunction con1, conjunction con2);
    bool isEqual(conjunction con1, conjunction con2);
    conjunction Combine(conjunction& con1, conjunction& con2);
    bool isCombined(const vector<conjunction>& conjunctions);

private:
    vector<conjunction> _conjunctions;
    vector<conjunction> _implicants;
};
