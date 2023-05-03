#include "Set.cpp"

int main() {
	try {
		Set s1;
		(((((s1 |= 1) |= 4) |= 3) |= 1) |= 5) |= 1;
		s1 |= 2;
		cout << "s1 : " << s1;
		// s1 |= 6;

		int i;
		cout << "Index: ";
		cin >> i;

		cout << s1[i] << "\n";
	}
	catch(int) {
		cout << "ERROR!" << endl;
	}

	return 0;
}