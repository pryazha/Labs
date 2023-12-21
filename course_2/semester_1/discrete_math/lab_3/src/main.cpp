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
    string str;
    cout << "Enter input string: ";
    getline(cin, str);

    while (!minimizer.IsValid(str)) {
        cout << "String is not valid, please enter new string: ";
        getline(cin, str);
    }

    minimizer.StringToConjunctions(str);
    minimizer.PrintMatrix(str);
    cout << '\n';
    vector<conjunction> implicants = minimizer.GetImplicants();
    minimizer.PrintCoverageTable(implicants);

    return 0;
}
