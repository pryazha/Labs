#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

class Minimizer {
public:
    bool IsValid(const string& str);
    vector<int> StringToVector(const string& str);
    vector<vector<int>> VectorToMatrix(const vector<int>& vec);
    bool PrintMatrix(const vector<vector<int>>& matrix);
};

