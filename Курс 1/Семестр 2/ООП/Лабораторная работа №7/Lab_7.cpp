#include "Set.cpp"
#include "Money.cpp"
#include <iostream>
using namespace std;

int main() {
	Set<int> A;
	(A |= 1) |= 10;
	cout << "A: " << A << "\n";

	Set<int> B;
	((B |= 2) |= 1) |= 10;
	cout << "B: " << B << "\n";

	A |= 2;
	if (A==B)
		cout << "A == B\n";
	else
		cout << "A != B\n";

	B[1] = 3;
	cout << "B[1]: " << B[1] << "\n";

	if (A==B)
		cout << "A == B\n";
	else
		cout << "A != B\n";

	if (A<2)
		cout << "A < 2\n";
	else
		cout << "A != 2\n";

	Money m1;
	cin >> m1;
	cout << "m1: " << m1 << "\n";
	Money m2;
	cin >> m2;
	cout << "m2: " << m2 << "\n";

	cout << m1 + m2 << "\n";

	Set<Money> C(2, m1);
	Set<Money> D(2, m2);
	cout << "\nC: " << C << "\n";
	cout << "D: " << D << "\n";

	D = C;
	cout << "D: " << D << "\n";
	cout << "C[0]: " << C[0] << "\n";
	 
	return 0;
}