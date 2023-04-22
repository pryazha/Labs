#include <iostream>
using namespace std;

class Set {
public:
	Set(int s);
	Set();
	~Set();

	Set& operator |=(int n);
	Set& operator =(const Set& other);
	bool operator !=(const Set& other);
	bool operator <(int key) const;
	int& operator [](int index);

	friend ostream& operator <<(ostream& out, const Set& other);

private:
	int* elements;
	int size;
};