#include "Money.cpp"
#include <iostream>
using namespace std;

int main() {
	Money a;
	Money b;
	cin >> a;
	cin >> b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	return 0;
}