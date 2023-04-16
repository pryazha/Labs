#include "Object.h"
#include "Date.cpp"
#include "Vector.cpp"
#include <iostream>
using namespace std;

int main() {
	Vector v(5);
	Triad a;
	cin >> a;
	Date b;
	cin >> b;

	Object *p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;
	return 0;
}