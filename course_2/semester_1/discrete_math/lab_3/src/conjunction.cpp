#include "conjunction.h"

conjunction::conjunction(int x, int y, int z, int w) {
    _bits = { x, y, z, w };
    combined = false;
}

void conjunction::Print() {
    if (_bits[0] == 1)
        cout << "x";
    else if (_bits[0] != -1)
        cout << "x'";

    if (_bits[1] == 1)
        cout << "y";
    else if (_bits[1] != -1)
        cout << "y'";

    if (_bits[2] == 1)
        cout << "z";
    else if (_bits[2] != -1)
        cout << "z'";
    
    if (_bits[3] == 1)
        cout << "w";
    else if (_bits[3] != -1)
        cout << "w'";
}

int conjunction::CountOnes() {
    int count = 0;
    for (int bit : _bits)
        if (bit == 1)
            count++;
    return count;
}

int conjunction::CountBits() {
    int count = 0;
    for (int bit : _bits)
        if (bit != -1)
            count++;
    return count;
}

int conjunction::getLength() {
    return _bits.size();
}

int conjunction::getBit(unsigned int index) {
    return _bits[index];
}

string conjunction::getString() {
    string str;

    if (_bits[0] == 1)
        str += "x";
    else if (_bits[0] != -1)
        str += "x'";

    if (_bits[1] == 1)
        str += "y";
    else if (_bits[1] != -1)
        str += "y'";

    if (_bits[2] == 1)
        str += "z";
    else if (_bits[2] != -1)
        str += "z'";
    
    if (_bits[3] == 1)
        str += "w";
    else if (_bits[3] != -1)
        str += "w'";

    return str;
}

void conjunction::setBit(unsigned int index, int bit) {
    _bits[index] = bit;
}

bool conjunction::isCombined() {
    return combined;
}

void conjunction::setCombined(bool combined) {
    this->combined = combined;
}
