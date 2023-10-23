#include "Money.h"

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

bool Money::operator >(const Money& other) {
	int temp1 = rub * 100 + kop;
	int temp2 = other.rub * 100 + other.kop;
	return temp1 > temp2;
}
bool Money::operator <(const Money& other) {
	int temp1 = rub * 100 + kop;
	int temp2 = other.rub * 100 + other.kop;
	return temp1 < temp2;
}
bool Money::operator ==(const Money& other) {
	int temp1 = rub * 100 + kop;
	int temp2 = other.rub * 100 + other.kop;
	return temp1 == temp2;
}

istream& operator >>(istream& in, Money&t) {
	int kop, rub, res;
	cout << "Rubles: ";
	in >> rub;
	cout << "Kopecks: ";
	in >> kop;
	res = rub * 100 + kop;
	t.rub = res / 100;
	t.kop = kop % 100;
	return in;
}
ostream& operator <<(ostream& out, const Money& t) {
	return (out << t.rub << "." << t.kop << " rub.\n");
}

fstream& operator >>(fstream& fin, Money& m) {
	
	fin >> m.rub;
	fin >> m.kop;
	return fin;
}
fstream& operator <<(fstream& fout, const Money& m) {
	fout << m.rub << "\n" << m.kop << "\n";
	return fout;
}