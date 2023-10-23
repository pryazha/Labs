#include "Triad.cpp"

class Date : public Triad {
public:
	Date();
	~Date();
	Date(int, int, int);
	Date(const Date &);
	Date& operator =(const Date&);
	bool operator ==(const Date&);
	bool operator !=(const Date&);
	bool operator >(const Date&);
	bool operator <(const Date&);
	friend istream& operator>>(istream&in, Date&o);
	friend ostream& operator<<(ostream&out, Date&o);
};