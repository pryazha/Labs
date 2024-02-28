#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::string;

class conjunction {
public:
    conjunction(int x, int y, int z, int w);

    int CountOnes();
    int CountBits();
    int getLength();
    int getBit(unsigned int index);
    string getString();
    void setBit(unsigned int index, int bit);
    bool isCombined();
    void setCombined(bool combined);

    void Print();

private:
    bool combined;
    vector<int> _bits;
};
