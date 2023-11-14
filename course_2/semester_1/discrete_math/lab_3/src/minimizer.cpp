#include "minimizer.h"

bool Minimizer::IsValid(const string& str) {
    if (str.size() == 16) {
        for (int i = 0; i < str.size(); i++)
            if (str[i] != '1' || str[i] != '0')
                return false;
        return true;
    }
    return false;
}
