#include "Money.h"
#include <iostream>
using namespace std;

Money&Money::operator=(const Money&t) {
	if (&t == this) 
		return *this;
	rub = t.rub;
	kop = t.kop;
	return *this;
}

Money Money::operator+(const Money&t) {
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 + temp2) / 100;
	p.kop = (temp1 + temp2) % 100;
	return p; 
}

Money Money::operator-(const Money&t) {
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 - temp2) / 100;
	p.kop = (temp1 - temp2) % 100;
	return p;
}

istream&operator>>(istream&in, Money&t) {
	cout << "Rubles: ";
	in >> t.rub;
	cout << "Kopecks: ";
	in >> t.kop;
	return in;
}

ostream&operator<<(ostream&out, const Money&t) {
	return (out << t.rub << "." << t.kop << " rub.");
}