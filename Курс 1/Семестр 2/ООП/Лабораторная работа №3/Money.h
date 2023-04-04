#include <iostream>
using namespace std;

class Money {
	long int rub;
	int kop;
public:
	Money() {
		rub = 0;
		kop = 0;
	}

	Money(int rub, int kop) {
		this->rub = rub;
		this->kop = kop;
	}

	Money(const Money &other) {
		rub = other.rub;
		kop = other.kop;
	}

	~Money() {};
	int get_rub() {
		return rub;
	}
	int get_kop() {
		return kop;
	}
	void set_rub(int rub) {
		this->rub = rub;
	}
	void set_kop(int kop) {
		this->kop = kop;
	}

	Money& operator=(const Money&);
	Money operator+(const Money&);
	Money operator-(const Money&);
	friend istream& operator>>(istream&in, Money&t);
	friend ostream& operator<<(ostream&out, const Money&t);
};