#include <iostream>
#include "Triad.cpp"
#include "Date.cpp"
using namespace std;

void f1(Triad& t) {
	t.
}

int main() {
	Triad a;
	cin >> a;
	cout << a;
	Triad b(34, 23, 3);
	cout << b;
	a = b;
	cout << a;

	Date d_1;
	Date d_2(22, 03, 2003);
	Date d_3;
	cin >> d_1;
	cout << d_1;
	cin >> d_3;
	cout << d_3;
	return 0;
}