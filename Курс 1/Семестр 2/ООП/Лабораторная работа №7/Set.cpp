#include "Set.h"

template <class T>
Set<T>::Set(int s, T k) {
	size = s;
	elements = new T[size];
	for (int i = 0; i < size; i++)
		elements[i] = k;
}

template <class T>
Set<T>::Set() {
	size = 0;
	elements = new T[size];
}

template <class T>
Set<T>::~Set() {
	delete[] elements;
	size = 0;
}

template <class T>
Set<T>& Set<T>::operator =(const Set<T>& other) {
	if (this == &other)
		return *this;

	size = other.size;
	if (elements != 0)
		delete[] elements;

	elements = new T[size];
	for (int i = 0; i < size; i++)
		elements[i] = other.elements[i];

	return *this;
}

template <class T>
bool Set<T>::operator !=(const Set<T>& other) {
	bool flag;
	if (size != other.size)
		return false;
	for (int i = 0; i < size; i++)
		flag = (elements[i] == other.elements[i]);
	return flag;
}
template <class T>
bool Set<T>::operator ==(const Set<T>& other) {
	if (size != other.size)
		return false;
	for (int i = 0; i < size; i++)
		if (elements[i] != other.elements[i])
			return false;
	return true;
}

template <class T>
bool Set<T>::operator <(T key) const {
	for (int i = 0; i < size; i++)
		if (key == elements[i])
			return true;
	return false;
}

template <class T>
T& Set<T>::operator [](int index) {
	if (index < size)
		return elements[index];
	else
		throw out_of_range("Index doesn't exist");
}

template <class T>
Set<T>& Set<T>::operator |=(T key) {
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

template <class T>
ostream& operator <<(ostream& out, const Set<T>& s) {
	out << "[ ";
	for (int i = 0; i < s.size; i++)
		out << s.elements[i] << " ";
	out << "]\n";
	return out;
}