#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> Conjuction;


class Quine_minimization {
    vector<int> func_vec;
    vector<Conjuction> conjuctions;
    vector<Conjuction> implicants;
    public:
    vector<int> stringToVec(string);
    void input_vec(string vec);

    void console_print_conjuctions(vector<Conjuction>);
    void print_mtx();
    void minimize();

    vector<Conjuction> get_implicants();
};

vector<int> Quine_minimization::stringToVec(string str) {
    vector<int> res;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') {
            res.push_back(1);
        }
        if (str[i] == '0') {
            res.push_back(0);
        }
    }
    return res;
}

void Quine_minimization::input_vec(string vec) {
    if (vec.length() != 16) {
        cout << "Wrong vector size!" << endl;
        return;
    }
    for (int i = 0; i < 16; i++) {
        if (vec[i] != '1' && vec[i] != '0') {
            cout << "Wrong values in the input vector" << endl;
            return;
        }
    }

    this->func_vec = stringToVec(vec);

    cout << "Vector is accepted" << endl;

    int i = 0;
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            for (int z = 0; z < 2; z++) {
                for (int w =0; w < 2; w++) {
                    if (func_vec[i] == 1) {
                        Conjuction curr = {x, y, z, w};
                        conjuctions.push_back(curr);
                    }
                    i++;
                }
            }
        }
    }
    cout << "Perfect disjunctive normal form have been made successfully" << endl;
    print_mtx();
    console_print_conjuctions(conjuctions);
}

vector<Conjuction> Quine_minimization::get_implicants() {
    // 1 step gettihg 3 vars
    for (int i = 0; i < conjuctions.size(); i++) {
        for (int j = i; j < conjuctions.size(); j++) {
            int numb_same = 0;
            Conjuction curr = vector<int>(4, -1);
            for (int k = 0; k < 4; k++) {
                if (conjuctions[i][k] == conjuctions[j][k]) {
                    numb_same++;
                    curr[k] = conjuctions[i][k];
                }
            }
            if (numb_same == 3 && find(implicants.begin(), implicants.end(), curr) == implicants.end()) {
                implicants.push_back(curr);
            }
        }
    }
    // 2 step getting 2 vars
    for (int i = 0; i < implicants.size(); i++) {
        for (int j = i; j < implicants.size(); j++) {
            int numb_same = 0;
            Conjuction curr = vector<int>(4, -1);
            for (int k = 0; k < 4; k++) {
                if (implicants[i][k] == implicants[j][k]) {
                    numb_same++;
                    curr[k] = implicants[i][k];
                }
            }
            if (numb_same == 2 && find(implicants.begin(), implicants.end(), curr) == implicants.end()) {
                implicants.push_back(curr);
            }
        }
    }

    return implicants;
}

void Quine_minimization::console_print_conjuctions(vector<Conjuction> vec) {
    cout << "Conjuctions" << endl;
    for (int i = 0; i < vec.size(); i++) {
        Conjuction curr_conj = vec[i];
        for (int k = 0; k < 4; k++)
            if (curr_conj[k] == 1)
                cout << " ";
            else if (curr_conj[k] == 0)
                cout << "_";

        if (i != vec.size()-1) {
            cout << "   ";
        }
    }
    cout << endl;
    for (int i = 0; i < vec.size(); i++) {
        Conjuction curr_conj = vec[i];
        if (curr_conj[0] != -1)
            cout << "x";
        if (curr_conj[1] != -1)
            cout << "y";
        if (curr_conj[2] != -1)
            cout << "z";
        if (curr_conj[3] != -1)
            cout << "w";
        if (i != vec.size()-1) {
            cout << " v ";
        }
    }
    cout << endl;
}

void Quine_minimization::print_mtx() {
    cout << "x y z w f" << endl;
    int i = 0;
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            for (int z = 0; z < 2; z++) {
                for (int w =0; w < 2; w++) {
                    cout << x << " " << y << " " << z << " " << w << " ";
                    if (func_vec[i] == 1) {
                        cout << 1 << endl;
                    }
                    else {
                        cout << 0 << endl;
                    }
                    i++;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    Quine_minimization minimizer;
    string str = "1100110011000010";
    minimizer.input_vec(str);
    cout << "\n";
    minimizer.console_print_conjuctions(minimizer.get_implicants());
    return 0;
}

