#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error {
public:
	Error(string str) {
		this->str = str;
	}

	void what() {
		cout << str << endl;
	}

private:
	string str;
};
