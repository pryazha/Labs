#include "Vector.h"
#include "Money.h"

int main() {
	Vector<Money> vec(5);
	vec.Print();

	Money m;
	cout << "Key:\n";
	cin >> m;
	vec.add_element(m);
	vec.Print();

	cout << "Data of del element:\n";
	cin >> m;
	vec.delete_element(m);
	vec.Print();

	vec.elements_reduction();
	vec.Print();
}