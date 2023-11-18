#include "minimizer.h"
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::getline;
using std::string;

int main() {
    Minimizer minimizer;

    string str;
    cout << "Enter input string: ";
    getline(cin, str);

    while (!minimizer.IsValid(str)) {
        cout << "String is not valid, please enter new string: ";
        getline(cin, str);
    }

    return 0;
}

