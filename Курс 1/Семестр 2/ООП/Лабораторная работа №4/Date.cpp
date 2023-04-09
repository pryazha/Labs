#include "Date.h"

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
	if (third < other.third)
		return false;
	else if (second < other.second)
		return false;
	else if (first <= other.first)
		return false;
	else
		return true;
}

bool Date::operator <(const Date& other) {
	if (third > other.third)
		return false;
	else if (second > other.second)
		return false;
	else if (third >= other.third)
		return false;
	else
		return true;
}

istream& operator>>(istream&in, Date& d) {
	cout << "\nDay: ";
	cin >> d.first;
	while (d.first > 31) {
		cout << "this day does not exist, please enter a new value: ";
		cin >> d.first;
	}
	cout << "Month: ";
	cin >> d.second;
	while (d.second > 12) {
		cout << "this month does not exist, please enter a new value: ";
		cin >> d.second;
	}
	cout << "Year: ";
	cin >> d.third;
	return in;
}

ostream& operator<<(ostream&out, Date& d) {
	cout << "Date: " << d.first << "." << d.second << "." << d.third;
	return out;
}