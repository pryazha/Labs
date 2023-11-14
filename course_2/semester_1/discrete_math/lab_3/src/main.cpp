#include "minimizer.h"
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    Minimizer minimizer;

    string str;
    cout << "Enter input string: ";
    cin >> str;

    while (!minimizer.IsValid(str)) {
        cout << "String is not valid, please enter new string: ";
        cin >> str;
    }

    return 0;
}

