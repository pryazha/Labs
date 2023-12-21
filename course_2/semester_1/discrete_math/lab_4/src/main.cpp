#include "functional_completeness.h"

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
    vector<string> functions = {
        "1101 0010",
        "1001",
        "01"
    };
    
    FunctionalCompleteness com;

    com.InputFunctions(functions);
    cout << "Input vectors:\n";
    com.PrintFunctions(functions);
    com.isFunctionalComplete();

    return 0;
}
