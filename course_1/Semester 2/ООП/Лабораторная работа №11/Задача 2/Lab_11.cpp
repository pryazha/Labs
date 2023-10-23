#include <cstdlib>
#include <vector>
#include "Money.h"

vector<Money> make_vector(int n) {
	vector<Money> v;
	Money m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}
	return v;
}
void print_vector(vector<Money> v) {
	cout << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << "\n";
}

void add_element(vector<Money>& v, Money key) {
	vector<Money>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		if (*it == key) break;
	if (it == v.end()) {
		cout << "Element doesn't exist\n"; 
		return; 
	}
	int num;
	cout << "Number: ";
	cin >> num;
	v.insert(v.begin()+num, key);
} 

void delete_element(vector<Money>& v, Money key) {
	vector<Money>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		if (*it == key)
			break;
	if (it == v.end()) {
		cout << "Element doesn't exist";
		return;
	}
	v.erase(it);
}

void elements_reduction(vector<Money>& v) {
	Money max(0, 0);
	Money min(999, 999);
	vector<Money>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
	}
	cout << "Max:\n" << max;
	cout << "Min:\n" << min;
	Money red = max - min;
	cout << "Reduction:\n" << red;
	for (it = v.begin(); it != v.end(); it++)
		*it = *it - red;
}

int main() {
	try {
		vector<Money> v;
		vector<Money>::iterator it;
		int numberOfElements;
		cout << "Number of elements: ";
		cin >> numberOfElements;
		v = make_vector(numberOfElements);
		print_vector(v);

		Money key;
		cout << "Key:\n";
		cin >> key;
		add_element(v, key);
		print_vector(v);

		cout << "Data of del element:\n";
		cin >> key;
		delete_element(v, key);
		print_vector(v);

		elements_reduction(v);
		print_vector(v);
	} catch(int) {
		cout << "Error!";
	}
	return 0;
}