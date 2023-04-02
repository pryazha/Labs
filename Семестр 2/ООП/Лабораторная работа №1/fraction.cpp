#include <iostream>
#include <cmath>
#include "fraction.h"
using namespace std;

void fraction::Init(double F, double S) {
	first = F;
	second = S;
}

void fraction::Read() {
	cout << "\nfirst: ";
	cin >> first;
	cout << "\nsecond: ";
	cin >> second;
}

void fraction::Show() {
	cout << "\nfirst: " << first;
	cout << "\nsecond: " << second << "\n";
}

double fraction::distance() {
	return sqrt(pow(first) + pow(second)); 
}