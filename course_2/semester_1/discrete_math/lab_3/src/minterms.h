#pragma once
#include <vector>
#include <string>
using std::vector;

class minterm {
public:
    minterm(unsigned int number);

    minterm operator +(const minterm& other);

private:
    int ones;
    vector<char> bits;
    bool combined;
};

class mintermGroup {
public:
    mintermGroup(int ones, vector<minterm> minterms);

private:
    int ones;
    vector<minterm> minterms;
};
