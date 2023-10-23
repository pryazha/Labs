#pragma once
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Vector {
	vector<T> v;
	int len;
public:
	Vector();
	Vector(int n);
	void Print();
	~Vector();

	void add_element(T key);
	void delete_element(T key);
	void elements_reduction();
};

template <class T>
void Vector<T>::add_element(T key) {
	int i = 0;
	for (i; i < v.size(); i++)
		if (v[i] == key)
		break;
	if (i == v.size()) {
		cout << "Element doesn't exist\n"; 
		return; 
	}
	int num;
	cout << "Number: ";
	cin >> num;
	v.insert(v.begin()+num, key);
} 

template <class T>
void Vector<T>::delete_element(T key) {
	int i = 0;
	for (i; i < v.size(); i++)	
		if (v[i] == key)
			break;
	if (i == v.size()) {
		cout << "Element doesn't exist";
		return;
	}
	v.erase(v.begin()+i);
}

template <class T>
void Vector<T>::elements_reduction() {
	T max = v[0];
	T min = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > max)
			max = v[i];
		if (v[i] < min)
			min = v[i];
	}
	cout << "Max:\n" << max;
	cout << "Min:\n" << min;
	T red = max - min;
	cout << "Reduction:\n" << red;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] - red;
}

template <class T>
Vector<T>::Vector() {
	len = 0;
}

template <class T>
Vector<T>::~Vector() {
}

template <class T>
Vector<T>::Vector(int n) {
	T temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	len = v.size();
}

template <class T>
void Vector<T>::Print() {
	cout << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " "; 
	cout << "\n";
}
