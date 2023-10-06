#include "Menu.h"

void Menu::MenuEnter() {
	SetCalculator calc;
	calc.SetUniversum();
	int switchChoice;
	MySet A;
	MySet B;

	std::cout << "First set:\n";
	calc.FillSet(A);
	system("cls");
	std::cout << "Second set:\n";
	calc.FillSet(B);
	system("cls");

	MySet result;

	std::cout << "First set: ";
	A.Print();
	std::cout << "Second set: ";
	B.Print();

	do {
		Print();
		cin >> switchChoice;
		switch (switchChoice) {
		case 1:
			result = calc.Union(A, B);
			break;
		case 2:
			result = calc.Intersection(A, B);
			break;
		case 3:
			int choiceSet;
			std::cout << "Which set you want to complement:\n";
			std::cout << "1. First set\n";
			std::cout << "2. Second set\n> ";
			cin >> choiceSet;
		while (choiceSet != 1 && choiceSet != 2) {
				std::cout << "That choice does not exist, enter new value: ";
				cin >> choiceSet;
			}
			if (choiceSet == 1) {
				A = calc.AbsComplement(A);
			}
			else {
				B = calc.AbsComplement(B);
			}
			break;
		case 4:
			result = calc.Diff(A, B);
			break;
		case 5:
			result = calc.SymDiff(A, B);
			break;
		default:
			std::cout << "That choice does not exist";
			break;
		}
		system("cls");
		std::cout << "First set: ";
		A.Print();
		std::cout << "Second set: ";
		B.Print();
		std::cout << "Result: ";
		result.Print();
	} while (switchChoice != 0);
}

void Menu::Print() {
	std::cout << "1. Union\n";
	std::cout << "2. Intersection\n";
	std::cout << "3. AbsComplement\n";
	std::cout << "4. Different\n";
	std::cout << "5. Symmetric different\n";
	std::cout << "0. Exit\n> ";
}

