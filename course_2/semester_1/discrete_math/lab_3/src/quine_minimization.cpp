#include "quine_minimization.h"

bool QuineMinimization::IsValid(string& str) {
   str.erase(remove_if(str.begin(), str.end(), isspace), str.end()); 
    if (str.size() == 16) {
        for (int i = 0; i < str.size(); i++)
            if (str[i] != '1' && str[i] != '0')
                return false;
        return true;
    }
    return false;
}

void QuineMinimization::StringToConjunctions(const string& str) {
int i = 0;
for (int x = 0; x < 2; x++)
    for (int y = 0; y < 2; y++)
        for (int z = 0; z < 2; z++)
            for (int w = 0; w < 2; w++) {
                if (str[i] == '1') {
                    conjunction curr(x, y, z, w);
                    _conjunctions.push_back(curr);
                }
                i++;
            }
}

void QuineMinimization::PrintMatrix(const string& str) {
    std::cout << "x y z w  f\n";
    int i = 0;
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            for (int z = 0; z < 2; z++)
                for (int w = 0; w < 2; w++) {
                    if (str[i] == '1')
                        std::cout << x << " " << y << " " << z << " " << w << "  1\n";
                    else
                        std::cout << x << " " << y << " " << z << " " << w << "  0\n";
                    i++;
                }
    std::cout << "\nSDNF: ";

    PrintConjunctions(_conjunctions);
}

void QuineMinimization::PrintConjunctions(vector<conjunction> conjunctions) {
    if (conjunctions.size() == 0)
        return;
    for (int i = 0; i < conjunctions.size(); i++) {
        conjunctions[i].Print();
        if (i != conjunctions.size() - 1)
            std::cout << " + ";
    }
    std::cout << '\n';
}

void QuineMinimization::PrintCoverageTable(vector<conjunction> implicants) {
    const int width = 10;
    cout << left << setw(width) << "";
    for (int i = 0; i < _conjunctions.size(); i++) {
        cout << left << setw(width) << _conjunctions[i].getString();
    }
    cout << '\n';
    
    for (int i = 0; i < implicants.size(); i++) {
        cout << left << setw(width) << implicants[i].getString();
        for (int j = 0; j < _conjunctions.size(); j++) {
            if (partOfConjunction(implicants[i], _conjunctions[j]))
                cout << left << setw(width) << "+";
            else
                cout << left << setw(width) << "";
        }
        cout << "\n\n";
    }
}

bool QuineMinimization::partOfConjunction(conjunction con1, conjunction con2) {
    int matchedCount = 0;
    int implicantBits = 0;

    for (int i = 0; i < con1.getLength(); i++) {
        if (con1.getBit(i) == con2.getBit(i))
            matchedCount++;
        if (con1.getBit(i) != -1)
            implicantBits++;
    }

    if (matchedCount == implicantBits)
        return true;

    return false;
}

vector<conjunction> QuineMinimization::GetImplicants() {
    vector<conjunction> result;

    bool combined = false;
    vector<conjunction> uncombinedCon = _conjunctions;
    vector<conjunction> combinedCon;

    do {
        deleteDublicates(uncombinedCon);

        for (int i = 0; i < uncombinedCon.size() - 1; i++)
            for (int j = i + 1; j < uncombinedCon.size(); j++)
                if (canBeCombined(uncombinedCon[i], uncombinedCon[j]))
                    combinedCon.push_back(Combine(uncombinedCon[i], uncombinedCon[j]));

        int uncombinedCount = 0;

        for (int i = 0; i < uncombinedCon.size(); i++)
            if (!uncombinedCon[i].isCombined()) {
                result.push_back(uncombinedCon[i]);
                uncombinedCount++;
            }

        if (uncombinedCount == uncombinedCon.size())
            combined = true;

        uncombinedCon.clear();
        uncombinedCon = combinedCon;
        combinedCon.clear();
    } while (!combined);

    return result;
}

void QuineMinimization::deleteDublicates(vector<conjunction>& conjunctions) {
    vector<conjunction> result;
    bool inVector;

    for (int i = 0; i < conjunctions.size(); i++) {
        inVector = false;
        for (int j = 0; j < result.size(); j++)
            if (isEqual(conjunctions[i], result[j])) {
                inVector = true;
                break;
            }
        if (!inVector)
            result.push_back(conjunctions[i]);
    }

    conjunctions = result;
}

bool QuineMinimization::canBeCombined(conjunction con1, conjunction con2) {
    if (con1.CountBits() != con2.CountBits() || isEqual(con1, con2))
        return false;

    int diff = 0;
    for (int i = 0; i < con1.getLength(); i++)
        if (con1.getBit(i) != con2.getBit(i))
            diff++;

    if (diff > 1)
        return false;
    
    return true;
}

bool QuineMinimization::isEqual(conjunction con1, conjunction con2) {
    for (int i = 0; i < con1.getLength(); i++)
        if (con1.getBit(i) != con2.getBit(i))
            return false;
    return true;
}

conjunction QuineMinimization::Combine(conjunction& con1, conjunction& con2) {
    conjunction result(-1, -1, -1, -1);

    for (int i = 0; i < 4; i++)
        if (con1.getBit(i) != con2.getBit(i))
            result.setBit(i, -1);
        else
            result.setBit(i, con1.getBit(i));

    con1.setCombined(true);
    con2.setCombined(true);
    return result;
}
