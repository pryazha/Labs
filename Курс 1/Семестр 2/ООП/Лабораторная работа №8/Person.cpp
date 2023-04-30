#include "Person.h"

Person::Person() {
	name = "";
	age = 0;
}
Person::~Person() {
}
Person::Person(string n, int a) {
	name = n;
	age = a;
}
Person::Person(const Person& other) {
	name = other.name;
	age = other.age;
}

Person& Person::operator =(const Person& other) {
	if (&other == this)
		return *this;
	name = other.name;
	age = other.age;
	return *this;
}

void Person::Show() {
	cout << "Name: " << name;
	cout << "\nAge: " << age;
	cout << "\n";
}
void Person::Input() {
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
	cout << "\n";
}