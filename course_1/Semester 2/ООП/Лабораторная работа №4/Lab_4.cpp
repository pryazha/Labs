#include <iostream>
#include "Date.cpp"
using namespace std;


int main() {
	Triad a;
	cin >> a;
	cout << a;
	Triad b(34, 23, 3);
	cout << b;
	a = b;
	cout << a;

	Date d1;
	Date d2(22, 03, 2003);
	Date d3;
	cin >> d1;
	cin >> d3;
	cout << "\nDate 1: " << d1 << endl;
	cout << "Date 2: " << d2 << endl;
	cout << "Date 3: " << d3 << endl;

	cout << "\nd1 == d2: " << (d1 == d2) << endl;
	cout << "d1 != d3: " << (d1 != d3) << endl;
	cout << "d2 > d3: " << (d2 > d3) << endl;
	cout << "d3 < d1: " << (d3 < d1) << endl;

	return 0;
}