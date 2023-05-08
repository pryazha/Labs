#include "Money.h"
#include "file_work.h"

int main() {
	// Money A;
	// cin >> A;
	// cout << A;

	// Money B;
	// cin >> B;
	// cout << B;

	// if (A > B)
	// 	cout << "A > B\n";
	// else if (A < B)
	// 	cout << "A < B\n";
	// else
	// 	cout << "A == B\n";

	int k, switch_op;
	Money m1, m2;
	char file_name[30];
	do {
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete record from file";
		cout << "\n4. Add record to file";
		cout << "\n5. Change record in file";
		cout << "\n6. Delete records in the range from k1 to k2";
		cout << "\n0. Exit\n";
		cin >> switch_op;
		switch(switch_op) {
			case 1:
				cout << "File name: ";
				cin >> file_name;
				k = make_file(file_name);
				if (k < 0)
					cout << "Can't make file";
				break;
			case 2:
				cout << "File name: ";
				cin >> file_name;
				k = print_file(file_name);
				if (k == 0)
					cout << "File is empty\n";
				if (k < 0)
					cout << "Can't read file\n";
				break;
			case 3:
				cout << "File name: ";
				cin >> file_name;
				int num;
				cout << "Number: ";
				cin >> num;
				k = del_file(file_name, num);
				if (k < 0)
					cout << "Can't read file\n";
				break;
			case 4:
				cout << "File name: ";
				cin >> file_name;
				cout << "Number: ";
				cin >> num;
				cout << "New element:\n";
				cin >> m1;
				k = add_file(file_name, num, m1);
				if (k < 0)
					cout << "Can't read file\n";
				if (k == 0)
					k = add_end(file_name, m1);
				break;
			case 5:
				cout << "File name: ";
				cin >> file_name;
				cout << "Number: ";
				cin >> num;
				cout << "New element:\n";
				cin >> m2;
				k = change_file(file_name, num, m2);
				if (k < 0)
					cout << "Can't read file\n";
				if (k == 0)
					cout << "Not such record\n";
				break;
			case 6:
				
				break;
		}
	}
	while (switch_op != 0);

	return 0;
}