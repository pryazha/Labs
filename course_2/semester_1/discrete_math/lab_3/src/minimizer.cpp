#include "minimizer.h"

bool Minimizer::IsValid(string& str) {
   str.erase(remove_if(str.begin(), str.end(), isspace), str.end()); 
    if (str.size() == 16) {
        for (int i = 0; i < str.size(); i++)
            if (str[i] != '1' && str[i] != '0')
                return false;
        return true;
    }
    return false;
}
