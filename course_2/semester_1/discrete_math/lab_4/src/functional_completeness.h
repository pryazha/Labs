#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::vector;
using std::string;
using std::left;
using std::setw;

class FunctionalCompleteness {
public:
    void PrintFunctions(const vector<string>& functions);
    void PrintTable();
    void isFunctionalComplete();
    void InputFunctions(vector<string>&);

private:
    void checkT0();
    void checkT1();
    void checkS();
    void checkM();
    void checkL();

    string ConvertTo8(const string&);
    bool isValidFunctions(vector<string>&);
    bool isValidFunction(string&);

    vector<string> _functions;
    vector<vector<bool>> _table;
};
