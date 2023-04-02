#include <iostream>
#include <cmath>
#include "fraction.cpp"
using namespace std;

fraction make_fraction(double F, double S) {
	fraction t;
	t.Init(F, S);
	return t;
}

int main() {
// Переменные A и B
	fraction A;
	fraction B;
	A.Init(3.0, 2.3);
	B.Read();
	A.Show();
	B.Show();
	cout << "A.distance(" << A.first << "," << A.second << ") = " << A.distance() << endl;
	cout << "B.distance(" << B.first << "," << B.second << ") = " << B.distance() << endl;
// Указатели
	fraction *X = new fraction;
	X->Init(2.3, 5.4);
	X->Show();
	cout << "X.distance(" << X->first << "," << X->second << ") = " << X->distance() << endl;
// Массивы
	fraction array[3];
	for (int i = 0; i < 3; i++)
		array[i].Read();
	for (int i = 0; i < 3; i++)
		array[i].Show();
	for (int i = 0; i < 3; i++)
		cout << "array[" << i << "].distance(" << array[i].first << "," << array[i].second << ") = " << array[i].distance() << endl;
// Динамические массивы
	fraction* p_array = new fraction[3];
	for (int i = 0; i < 3; i++)
		p_array[i].Read();
	for (int i = 0; i < 3; i++)
		p_array[i].Show();
	for (int i = 0; i < 3; i++)
		cout << "p_array[" << i << "].distance(" << p_array[i].first << "," << p_array[i].second << ") = " << p_array[i].distance() << endl;
// make_fraction()
	double x, y;
	cout << "first: ";
	cin >> x;
	cout << "second: ";
	cin >> y;
	fraction F = make_fraction(x, y);
	F.Show();
	return 0;
}