#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Money {
public:
	Money() {
		rub = 0;
		kop = 0;
	}

	Money(int rub, int kop) {
		int temp = rub + kop;
		this->rub = temp / 100;
		this->kop = kop % 100;
	}

	Money(const Money &other) {
		rub = other.rub;
		kop = other.kop;
	}

	~Money() {};

	Money& operator=(const Money&);
	Money operator+(const Money&);
	Money operator-(const Money&);

	bool operator >(const Money&);
	bool operator <(const Money&);
	bool operator ==(const Money&);

	friend istream& operator >>(istream& in, Money& t);
	friend ostream& operator <<(ostream& out, const Money& t);

	friend fstream& operator >>(fstream& fin, Money& m);
	friend fstream& operator <<(fstream& fout, const Money& m);

private:
	long int rub;
	int kop;
};