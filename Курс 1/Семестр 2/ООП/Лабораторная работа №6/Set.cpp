#include "Set.h"

Set::Set(int s) {
	size = s;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = 0;
}

Set::Set() {
	size = 0;
	elements = new int[size];
}

Set::~Set() {
	delete[] elements;
	size = 0;
}

Set& Set::operator =(const Set& other) {
	if (this == &other)
		return *this;

	size = other.size;
	if (elements != 0)
		delete[] elements;

	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = other.elements[i];

	return *this;
}

bool Set::operator !=(const Set& other) {
	bool flag;
	if (size != other.size)
		return false;
	for (int i = 0; i < size; i++)
		flag = (elements[i] == other.elements[i]);
	return flag;
}

bool Set::operator <(int key) const {
	for (int i = 0; i < size; i++)
		if (key == elements[i])
			return true;
	return false;
}

Set& Set::operator |=(int key) {
	for (int i = 0; i < size; i++)
		if (key == elements[i])
			return *this;
	int i, k;
	for (k = 0; k < size && elements[k] <= key; k++);
	if (k == size) {
		elements[size] = key;
	}
	else {
		for (i = size; i > k; i--)
			elements[i] = elements[i - 1];
		elements[k] = key;
	}
	size++;
	return *this;
}

ostream& operator <<(ostream& out, const Set& set) {
	out << "[ ";
	for (int i = 0; i < set.size; i++)
		out << set.elements[i] << " ";
	out << "]\n";
	return out;
}

int& Set::operator [](int index) {
	if (index < size) {
		return elements[index];
	}
	else
		cout << "Index doesn't exist";
}
