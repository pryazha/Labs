#include "functional_completeness.h"

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
    vector<string> functions = {
        "1",
        "1110 0011",
        "0001"
    };
    
    FunctionalCompleteness com;

    com.InputFunctions(functions);
    cout << "Input vectors:\n";
    com.PrintFunctions(functions);
    com.isFunctionalComplete();

    return 0;
}
