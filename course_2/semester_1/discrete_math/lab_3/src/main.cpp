#include "quine_minimization.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::getline;
using std::string;

int main() {
    QuineMinimization minimizer;
    string str1 = "1111 1100 1111 1100";
    string str2 = "1011 0011 0011 1111";
    string str = "1011 0011 0011 1111";
    // cout << "Enter input string: ";
    // getline(cin, str);

    while (!minimizer.IsValid(str)) {
        cout << "String is not valid, please enter new string: ";
        getline(cin, str);
    }

    minimizer.StringToConjunctions(str);
    minimizer.PrintMatrix(str);
    vector<conjunction> implicants = minimizer.GetImplicants();
    minimizer.PrintCoverageTable(implicants);
    cout << "MDNF: ";
    minimizer.PrintConjunctions(implicants);

    return 0;
}
