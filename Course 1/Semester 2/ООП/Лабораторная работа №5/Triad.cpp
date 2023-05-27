#include "Triad.h"
#include <iostream>
using namespace std;

Triad::Triad() {
	first = 0;
	second = 0;
	third = 0;	
}

Triad::Triad(int f, int s, int t) {
	first = f;
	second = s;
	third = t;
}

Triad::~Triad() {
}

Triad::Triad(const Triad& triad) {
	first = triad.first;
	second = triad.second;
	third = triad.third;
}

Triad& Triad::operator =(const Triad& other) {
	if (&other == this)
		return *this;
	first = other.first;
	second = other.second;
	third = other.third;
	return *this;
}

istream& operator >>(istream&in, Triad& other) {
	cout << "First: ";
	in >> other.first;
	cout << "Second: ";
	in >> other.second;
	cout << "Third: ";
	in >> other.third;
	return in;
}

ostream& operator <<(ostream&out, Triad& other) {
	out << "\nFirst : " << other.first;
	out << "\nSecond : " << other.second;
	out << "\nThird : " << other.third;
	out << "\n";
	return out;
}

void Triad::Show() {
	cout << "\nFirst : " << first;
	cout << "\nSecond : " << second;
	cout << "\nThird : " << third;
	cout << "\n";
}