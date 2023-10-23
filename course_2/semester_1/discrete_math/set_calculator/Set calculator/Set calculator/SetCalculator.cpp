#include "SetCalculator.h"

void SetCalculator::manualInput(MySet& set) {
	int size;
	cout << "Enter the size: ";
	cin >> size;
	while (size <= 0) {
		cout << "Size cannot be negative or zero, enter new size: ";
		cin >> size;
	}
	cout << "Enter values\n";
	for (int i = 0; i < size; i++) {
		int val;
		cin >> val;
		while (!inUniversum(val)) {
			cout << "Value cannot be outside universum, enter new value: ";
			cin >> val;
		}
		set.AddAtEnd(val);
	}
}

void SetCalculator::randomFilling(MySet& set) {
	int size;
	cout << "Enter set power: ";
	cin >> size;
	while (size <= 0) {
		cout << "Size cannot be negative or zero, enter new size: ";
		cin >> size;
	}
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		set.AddAtEnd(rand() % (maxU - minU + 1) + minU);
	}
}

void SetCalculator::conditionFilling(MySet& set) {
	bool isNegative;
	int choiceSign;
	cout << "Are the elements negative or positive?\n";
	cout << "1. Negative\n";
	cout << "2. Positive\n> ";
	cin >> choiceSign;

	while (choiceSign != 1 && choiceSign != 2) {
		cout << "That choice doesn't exist, please enter new value: ";
		cin >> choiceSign;
	}
	isNegative = choiceSign == 1;

	int multiplicity;
	cout << "Enter the multiplicity value: ";
	cin >> multiplicity;
	while (multiplicity == 0) {
		cout << "Invalid input, please enter new value: ";
		cin >> multiplicity;
	}

	int i = minU;
	while (i <= maxU) {
		if (i % multiplicity == 0) {
			if (isNegative) {
				if (i < 0) {
					set.AddAtEnd(i);
				}
			}
			else {
				if (i > 0) {
					set.AddAtEnd(i);
				}
			}
		}
		i++;
	}
	// sorry about that while, it's terrible
}

void SetCalculator::FillSet(MySet& set) {
	int choice;
	cout << "1. Create set using manual input\n";
	cout << "2. Create set using random filling\n";
	cout << "3. Create set using multiplicity condition\n> ";
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3) {
		cout << "That choice does not exist, please enter a new value: ";
		cin >> choice;
	}
	switch (choice) {
	case 1:
		manualInput(set);
		break;
	case 2:
		randomFilling(set);
		break;
	case 3:
		conditionFilling(set);
		break;
	}
}

MySet SetCalculator::Union(MySet& set1, MySet& set2) {
	MySet result;
	for (int i = 0; i < set1.size(); i++) {
		result.AddAtEnd(set1.set[i]);
	}
	for (int i = 0; i < set2.size(); i++) {
		if (!result.Find(set2.set[i])) {
			result.AddAtEnd(set2.set[i]);
		}
	}
	sort(result.set.begin(), result.set.end());
	return result;
}

MySet SetCalculator::Intersection(MySet& set1, MySet& set2) {
	MySet result;
	for (int i = 0; i < set1.size(); i++) {
		if (set2.Find(set1.set[i])) {
			result.AddAtEnd(set1.set[i]);
		}
	}
	return result;
}

MySet SetCalculator::AbsComplement(MySet& set) {
	MySet result;
	for (int i = minU; i <= maxU; i++) {
		if (!set.Find(i)) {
			result.AddAtEnd(i);
		}
	}
	return result;
}

MySet SetCalculator::Diff(MySet& set1, MySet& set2) {
	MySet result;
	for (int i = 0; i < set1.size(); i++) {
		if (!set2.Find(set1.set[i])) {
			result.AddAtEnd(set1.set[i]);
		}
	}
	return result;
}

MySet SetCalculator::SymDiff(MySet& set1, MySet& set2) {
	MySet result;
	for (int i = 0; i < set1.size(); i++) {
		if (!set2.Find(set1.set[i])) {
			result.AddAtEnd(set1.set[i]);
		}
	}
	for (int i = 0; i < set2.size(); i++) {
		if (!set1.Find(set2.set[i])) {
			result.AddAtEnd(set2.set[i]);
		}
	}
	return result;
}

void SetCalculator::SetUniversum() {
	int minU;
	cout << "Enter the min range value of universum: ";
	cin >> minU;
	this->minU = minU;
	int maxU;
	cout << "Enter the max range value of universum: ";
	cin >> maxU;
	while (maxU <= minU) {
		cout << "The maximum value of the universe cannot be less than or equal to the minimum, enter a new value: ";
		cin >> maxU;
	}
	this->maxU = maxU;
}

bool SetCalculator::inUniversum(int val) {
	if (val >= minU && val <= maxU) {
		return true;
	}
	return false;
}

string SetCalculator::ExpressionInput() {
	string expr;
	cout << "\"*\" - Intersection, \"+\" - Union, \"/\" - Difference, \"^\" - Symmetric difference\n";
	cout << "\"1\" - first set, \"2\" - second set, \"3\" - third set\n";
	cout << "Enter your expression: ";
	getline(cin, expr);
	while (expr == "") {
		cout << "Expression cannot be empty, please enter new expression: ";
		getline(cin, expr);
	}
	cout << "Your expression is: " << expr << ", right?(Y/y - (yes), N/n - (no)): ";
	char answer;
	cin >> answer;
	cin.ignore();
	while (answer != 'Y' && answer != 'y') {
		if (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
			cout << "That answer doesn't exist, please enter Y/y if your answer if yes or N/n if not: ";
			cin >> answer;
			cin.ignore();
		}
		if (answer == 'N' || answer == 'n') {
			cout << "Enter new expression: ";
			getline(cin, expr);
			while (expr == "") {
				cout << "Expression cannot be empty, please enter new expression: ";
				getline(cin, expr);
			}
			cout << "Your expression is: " << expr << ", right?(Y/y - (yes), N/n - (no)): ";
			cin >> answer;
			cin.ignore();
		}
	}
	return expr;
}

MySet SetCalculator::EvaluateExpr(string tokens, MySet setArr[]) {
	int i;
	stack<MySet> values;
	stack<char> ops;
	for (i = 0; i < tokens.length(); i++) {
		if (tokens[i] == ' ') {
			continue;
		}
		else if (tokens[i] == '(') {
			ops.push(tokens[i]);
		}
		else if (isdigit(tokens[i])) {
			int pos;
			pos = tokens[i] - '0';
			values.push(setArr[pos - 1]);
		}
		else if (tokens[i] == ')') {
			while(!ops.empty() && ops.top() != '(') {
				MySet val2 = values.top();
				values.pop();
				MySet val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(ApplyOp(val1, val2, op));
			}
			if (!ops.empty()) {
				ops.pop();
			}
		}
		else {
			while (!ops.empty() && Precedence(ops.top()) >= Precedence(tokens[i])) {
				MySet val2 = values.top();
				values.pop();
				MySet val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(ApplyOp(val1, val2, op));
			}
			ops.push(tokens[i]);
		}
	}
	while (!ops.empty()) {
		MySet val2 = values.top();
		values.pop();
		MySet val1 = values.top();
		values.pop();
		char op = ops.top();
		ops.pop();
		values.push(ApplyOp(val1, val2, op));
	}
	return values.top();
}

int SetCalculator::Precedence(char op) {
	if (op == '/' || op == '^') {
		return 1;
	}
	if (op == '+') {
		return 2;
	}
	if (op == '*') {
		return 3;
	}
	if (op == '\'') {
		return 4;
	}
	return 0;
}

MySet SetCalculator::ApplyOp(MySet& a, MySet& b, char op) {
	switch (op) {
	case '*':
		return Intersection(a, b);
	case '+':
		return Union(a, b);
	case '/':
		return Diff(a, b);
	case '^':
		return SymDiff(a, b);
	default:
		cout << "Error! Invalid operation\n";
	}
}

