#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Triad : public Object {
public:
	Triad();
	virtual ~Triad();
	void Show();
	Triad(int, int, int);
	Triad(const Triad&);

	int get_first() {
		return first;
	}
	int get_second() {
		return second;
	}
	int get_third() {
		return third;
	}

	void set_first(int first) {
		this->first = first;
	}
	void set_second(int second) {
		this->second = second;
	}
	void set_third(int third) {
		this->third = third;
	}

	Triad& operator =(const Triad&);
	friend istream& operator >>(istream&in, Triad&other);
	friend ostream& operator <<(ostream&out, Triad&other);

protected:	
	int first, second, third;
};