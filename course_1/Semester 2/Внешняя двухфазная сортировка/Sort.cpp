#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

void raspredelenie(string file1, string file2, string main)
{
	ofstream f1, f2;
	ifstream fmain;
	string temp, current;
	int itemp, icur;
	f1.open(file1);
	f2.open(file2);
	fmain.open(main);
	if (!f1.is_open() || !f2.is_open()) {
		cout << "File error" << endl;
	}
	else {
		bool firstFile = true;
		fmain >> current;
		while (!fmain.eof()) {
			if (firstFile) {
				f1 << current << "\n";
				temp = current;
				fmain >> current;
				if (fmain.eof()) {
					f1 << "/" << "\n";
					return;
				}
				itemp = stoi(temp);
				icur = stoi(current);
				while (itemp <= icur) {
					if (fmain.eof()) {
						f1 << "/" << "\n";
						return;
					}
					f1 << current << "\n";
					temp = current;
					fmain >> current;
					itemp = stoi(temp);
					icur = stoi(current);
				}
				f1 << "/" << "\n";
				firstFile = false;
			}
			else {
				f2 << current << "\n";
				temp = current;
				fmain >> current;
				if (fmain.eof()) {
					f2 << "/" << "\n";
					return;
				}
				itemp = stoi(temp);
				icur = stoi(current);
				while (itemp <= icur) {
					if (fmain.eof()) {
						f2 << "/" << "\n";
						return;
					}
					f2 << current << "\n";
					temp = current;
					fmain >> current;
					itemp = stoi(temp);
					icur = stoi(current);
				}
				f2 << "/" << "\n";
				firstFile = true;
			}
		}
	}
	f1.close();
	f2.close();
	fmain.close();
}

void MergeSort(string file1, string file2, string main) {
	raspredelenie(file1, file2, main);
	ifstream f1, f2;
	ofstream fmain;
	string temp1, temp2;
	int itemp1, itemp2;
	f1.open(file1);
	f2.open(file2);
	fmain.open(main);
	if (!f1.is_open() || !f2.is_open()) {
		cout << "File error" << endl;
	}
	else {
		int i = 0, j = 0;
		while (!(f1.eof())) {
			f1 >> temp1;
			f2 >> temp2;
			if (temp2 == "")
				return;
			while (temp1 != "/" || temp2 != "/") {
				if (temp1 == "/") {
					fmain << temp2 << "\n";
					f2 >> temp2;
				}
				else if (temp2 == "/") {
					fmain << temp1 << "\n";
					f1 >> temp1;
				}
				else {
					itemp1 = stoi(temp1);
					itemp2 = stoi(temp2);
					if (itemp1 <= itemp2) {
						fmain << temp1 << "\n";
						f1 >> temp1;
					}
					else {
						fmain << temp2 << "\n";
						f2 >> temp2;
					}
				}
			}
		}
	}
	f1.close();
	f2.close();
	fmain.close();
	MergeSort(file1, file2, main);
}

int main()
{
	srand(time(NULL));
	int size, element;
	string fres = "result.txt", tempfile = "temp.txt", fdata = "data.txt", temp;
	ofstream data;
	ifstream res;

	cout << "Enter size of array: ";
	cin >> size;

	cout << "Array before sort: ";
	data.open(fdata);
	for (int i = 0; i < size; i++) {
		element = rand() % 20;
		cout << element << " ";
		data << element << "\n";
	}
	data.close();

	MergeSort(fres, tempfile, fdata);

	cout << "\nSort array: ";
	res.open(fres);
	for (int i = 0; i < size; i++) {
		res >> temp;
		cout << temp << " ";
	}
	res.close();

	return 0;
}