#include "MySet.h"

MySet::MySet() {
}

void MySet::AddAtBegin(int val) {
	if (Find(val)) {
		return;
	}
	if (set.size() == 0) {
		set.push_back(val);
		return;
	}
	set.resize(set.size() + 1);
	for (int i = set.size() - 1; i > 0; i--) {
		set[i] = set[i - 1];
	}
	set[0] = val;
}

void MySet::AddAtEnd(int val) {
	if (Find(val)) {
		return;
	}
	set.push_back(val);
}

void MySet::Insert(int index, int val) {
	if (index < 0 || index >= set.size()) {
		throw("Invalid index");
		return;
	}
	if (Find(val)) {
		return;
	}
	if (index == 0) {
		AddAtBegin(val);
		return;
	}
	set.resize(set.size() + 1);
	for (int i = set.size() - 1; i > index; i--) {
		set[i] = set[i - 1];
	}
	set[index] = val;
}

bool MySet::Find(int val) {
	for (int i = 0; i < set.size(); i++) {
		if (val == set[i]) {
			return true;
		}
	}
	return false;
}

vector<int>::iterator& MySet::Get(int val) {
	vector<int>::iterator it;
	for (auto it = set.begin(); it != set.end(); it++) {
		if (*it == val) {
			return it;
		}
	}
}

void MySet::Print() {
	for (int i = 0; i < set.size(); i++) {
		cout << set[i] << " ";
	}
	cout << "\n";
}

