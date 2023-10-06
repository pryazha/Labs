#include "Menu.h"

void Menu::MenuEnter() {
	SetCalculator calc;
	calc.SetUniversum();
	int switchChoice;
	MySet setArr[4];

	for (int i = 0; i < 3; i++) {
		cout << "Set " << i + 1 << ":\n";
		calc.FillSet(setArr[i]);
		system("cls");
	}

	MySet newSet;

	PrintSetArray(setArr, 3);

	string expr;
	int firstSet, secondSet;
	int setChoice;
	do {
		Print();
		cin >> switchChoice;
		cin.ignore();

		switch (switchChoice) {
		case 1:
			firstSet = SelectSet("Select first set:\n");
			secondSet = SelectSet("Select second set:\n");
			setArr[3] = calc.Union(setArr[firstSet - 1], setArr[secondSet - 1]);
			break;

		case 2:
			firstSet = SelectSet("Select first set:\n");
			secondSet = SelectSet("Select second set:\n");
			setArr[3] = calc.Intersection(setArr[firstSet - 1], setArr[secondSet - 1]);
			break;

		case 3:
			int choiceSet;
			cout << "Which set you want to complement:\n";
			cout << "1. First set\n";
			cout << "2. Second set\n";
			cout << "3. Third set\n> ";
			cin >> choiceSet;

			while (choiceSet != 1 && choiceSet != 2 && choiceSet != 3) {
				cout << "That choice does not exist, please enter new value\n> ";
				cin >> choiceSet;
			}

			switch (choiceSet) {
			case 1:
				setArr[0] = calc.AbsComplement(setArr[0]);
				break;
			case 2:
				setArr[1] = calc.AbsComplement(setArr[1]);
				break;
			case 3:
				setArr[2] = calc.AbsComplement(setArr[2]);
				break;
			}

			break;

		case 4:
			firstSet = SelectSet("Select first set:\n");
			secondSet = SelectSet("Select second set:\n");
			setArr[3] = calc.Diff(setArr[firstSet - 1], setArr[secondSet - 1]);
			break;

		case 5:
			firstSet = SelectSet("Select first set:\n");
			secondSet = SelectSet("Select second set:\n");
			setArr[3] = calc.SymDiff(setArr[firstSet - 1], setArr[secondSet - 1]);
			break;


		case 6:
			expr = calc.ExpressionInput();
			setArr[3] = calc.EvaluateExpr(expr, setArr);
			break;

		case 7:
			setChoice;
			cout << "Select set, that you want to replace:\n";
			cout << "1. First set\n";
			cout << "2. Second set\n";
			cout << "3. Third set\n> ";
			cin >> setChoice;
			while (setChoice != 1 && setChoice != 2 && setChoice != 3) {
				cout << "That choice does not exist, please select new set:\n> ";
				cin >> setChoice;
			}
			cout << "Set " << setChoice << ":\n";
			calc.FillSet(newSet);
			setArr[setChoice - 1] = newSet;
			break;

		default:
			break;
		}
		system("cls");
		PrintSetArray(setArr, 3);
		if (expr != "") {
			cout << "Expr: " << expr << "\n";
			expr = "";
		}
		cout << "Result: ";
		setArr[3].Print();
	} while (switchChoice != 0);
}

void Menu::Print() {
	cout << "1. Union\n";
	cout << "2. Intersection\n";
	cout << "3. AbsComplement\n";
	cout << "4. Difference\n";
	cout << "5. Symmetric difference\n";
	cout << "6. Formula input\n";
	cout << "7. Replace set\n";
	cout << "0. Exit\n> ";
}

void Menu::PrintSetArray(MySet setArr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Set " << i + 1 << ": ";
		setArr[i].Print();
	}
}

int Menu::SelectSet(string message) {
	int choice;
	cout << message;
	cout << "1. First set\n";
	cout << "2. Second set\n";
	cout << "3. Third set\n";
	cout << "4. Result\n> ";
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
		cout << "That choice does not exist, please select new set:\n> ";
		cin >> choice;
	}
	return choice;
}
