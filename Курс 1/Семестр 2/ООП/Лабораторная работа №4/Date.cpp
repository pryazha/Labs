#include "Date.h"
#include "Triad.h"

Date::Date() : Triad() {
}

Date::~Date() {
}

Date::Date(int f, int s, int t) : Triad(f, s, t) {
}

Date::Date(const Date& other) {
	first = other.first;
	second = other.second;
	third = other.third;
}

Date& Date::operator =(const Date& other) {
	if (&other == this)
		return *this;
	first = other.first;
	second = other.second;
	third = other.third;
	return *this;
}

bool Date::operator ==(const Date& other) {
	return (first == other.first && second == other.second && third == other.third);
}

bool Date::operator !=(const Date& other) {
	return !(first == other.first && second == other.second && third == other.third);
}

bool Date::operator >(const Date& other) {
	return (first > other.first && second > other.second && third > other.third);
}

bool Date::operator <(const Date& other) {
	return (first < other.first && second < other.second && third < other.third);
}

istream& operator>>(istream&in, Date& d) {
	cout << "\nDay: ";
	cin >> d.first;
	cout << "\nMonth: ";
	cin >> d.second;
	cout << "\nYear: ";
	cin >> d.third;
	return in;
}

ostream& operator<<(ostream&out, Date& d) {
	cout << "Date: " << d.first << "." << d.second << "." << d.third;
	return out;
}