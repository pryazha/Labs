#pragma once
#include <vector>
using std::vector;

class minterm
{
public:
    minterm(vector<char> bits);

private:
    int ones;
    vector<char> bits;
    bool combined;
};

class mintermGroup
{
public:
    mintermGroup(int ones, vector<minterm> minterms);

private:
    int ones;
    vector<minterm> minterms;
};
