#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef list<double> List;

List make_list(int n) {
	List tempList;
	for (int i = 0; i < n; i++) {
		double tempElement = rand() % 11;
		tempList.push_back(tempElement);
	}
	return tempList;
}

void print_list(List lis) {
	list<double>::iterator it = lis.begin();
	cout << "Data: ";
	for (it; it != lis.end(); it++)
		cout << *it << " ";
	cout << "\n";
}

void insert_element(List& lis, double key) {
	list<double>::iterator it = lis.begin();
	for (it; it != lis.end(); it++)
		if (*it == key)
			break;
	if (it == lis.end()) {
		cout << "Element doesn't exist\n";
		return;
	}
	int num, i = 0;
	cout << "Number: ";
	cin >> num;
	for (it = lis.begin(); it != lis.end(); it++) {
		if (num == (i + 1))
			break;
		i++;
	}
	lis.insert(++it, key);
}
void delete_element(List& lis, double key) {
	list<double>::iterator it = lis.begin();
	for (it; it != lis.end(); it++)
		if (*it == key)
			break;
	if (it == lis.end()) {
		cout << "Element doesn't exist\n";
		return;
	}
	lis.erase(it);
}

void element_reduction(List& lis) {
	double max = 0, min = 12;
	list<double>::iterator it;
	for (it = lis.begin(); it != lis.end(); it++) {
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
	}
	cout << "Max: " << max << "\n";
	cout << "Min: " << min << "\n";
	double red = max - min;
	cout << "red: " << red << "\n";
	for (it = lis.begin(); it != lis.end(); it++)
		*it -= red;
}


int main() {
	try {
		srand(time(NULL));
		list<double> li;
		list<double>::iterator it = li.begin();
		int numberOfElements;
		cout << "Number of elements: ";
		cin >> numberOfElements;
		li = make_list(numberOfElements);
		print_list(li);

		double key;
		cout << "Data of element: ";
		cin >> key;
		insert_element(li, key);
		print_list(li);

		cout << "Data of del element: ";
		cin >> key;
		delete_element(li, key);
		print_list(li);

		element_reduction(li);
		print_list(li);
	}
	catch (int) {
		cout << "Error!";
	}
	return 0;
}