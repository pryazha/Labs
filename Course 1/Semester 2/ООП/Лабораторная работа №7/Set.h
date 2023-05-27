#include <iostream>
using namespace std;

template <class T>
class Set {
public:
	Set(int s, T k);
	Set();
	~Set();

	Set<T>& operator |=(T key);
	Set& operator =(const Set<T>& other);
	bool operator !=(const Set<T>& other);
	bool operator ==(const Set<T>& other);
	bool operator <(T key) const;
	T& operator [](int index);
 
	template <class T2>
	friend ostream& operator << (ostream&, const Set<T2>& s);
private:
	T* elements;
	int size;
};
