#include "Set.cpp"

int main() {
	try {
		Set s1;
		(((((s1 |= 1) |= 4) |= 3) |= 1) |= 5) |= 1;
		s1 |= 2;
		cout << "s1 : " << s1;
		// s1 |= 6;
		// cout << "s1 : " << s1;

		int i;
		cout << "Index: ";
		cin >> i;

		cout << s1[i] << "\n";

		Set s2;
		((((s2 |= 3) |= 2) |= 6) |= 5) |= 7;
		cout << "s2 : " << s2;

		s2 |= 1;
	}
	catch(Error& e) {
		e.what();
	}

	return 0;
}