#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Minimizer
{
public:
    bool IsValid(string& str);
    vector<int> StringToVector(const string& str);
    vector<vector<int>> VectorToMatrix(const vector<int>& vec);
    bool PrintMatrix(const vector<vector<int>>& matrix);
};

class Minterm
{
public:
    Minterm(unsigned int number = 0, unsigned int bitCount = 1);
    Minterm(vector<unsigned char> bits);
    
private:
    unsigned int ones, bitCount;
    vector<unsigned char> bits;
    bool combined;
};

