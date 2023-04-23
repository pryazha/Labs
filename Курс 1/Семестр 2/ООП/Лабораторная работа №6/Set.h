#include <iostream>
using namespace std;

class Iterator {
	friend class Set;
public:
	Iterator() {
		elem = 0;
	}
	Iterator(const Iterator& it) {
		elem = it.elem;
	}

	void operator++() {
		++elem;
	}
	void operator--() {
		--elem;
	}
	int& operator *() const {
		return *elem;
	}
	void operator +(int n) const {
		while (elem + n > size) {
			cout << "Index doesn't exist, please enter new value: ";
			cin >> n;
		}
		elem += n;
	}
private:
	int* elem;
};

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

	Iterator first() {
		return begin;
	}
	Iterator last() {
		return end;
	}

private:
	int* elements;
	int size;
	Iterator begin;
	Iterator end;
};
