#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
class Set {
public:
	Set(int s, int k);
	Set();
	~Set();

	Set& operator |=(int key);
	Set& operator =(const Set& other);
	bool operator !=(const Set& other);
	bool operator ==(const Set& other);
	bool operator <(int key) const;
	int& operator [](int index);
 
	friend ostream& operator <<(ostream&, const Set& s);
	
private:
	int* elements;
	int size;
};
