#include "Set.h"
#include "Error.h"

Set::Set(int s, int k) {
	if (s > MAX_SIZE)
		throw Error("Set length more than MAXSIZE\n");
	size = s;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = k;
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
bool Set::operator ==(const Set& other) {
	if (size != other.size)
		return false;
	for (int i = 0; i < size; i++)
		if (elements[i] != other.elements[i])
			return false;
	return true;
}

bool Set::operator <(int key) const {
	for (int i = 0; i < size; i++)
		if (key == elements[i])
			return true;
	return false;
}
int& Set::operator [](int index) {
	if (index < 0)
		throw Error("Index < 0\n");
	if (index >= size)
		throw Error("Index > size\n");
	return elements[index];
}
Set& Set::operator |=(int key) {
	for (int i = 0; i < size; i++)
		if (key == elements[i])
			return *this;
	if (size == MAX_SIZE)
		throw Error("Set lenght is max\n");
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

ostream& operator <<(ostream& out, const Set& s) {
	out << "[ ";
	for (int i = 0; i < s.size; i++)
		out << s.elements[i] << " ";
	out << "]\n";
	return out;
}
