#include "Abiturient.h"

Abiturient::Abiturient() : Person() {
	Number_of_points = 0;
	speciality = "";
}
Abiturient::Abiturient(string n, int a, int np, string s) : Person(n, a) {
	Number_of_points = np;
	speciality = s;
}
Abiturient::~Abiturient() {
}
Abiturient::Abiturient(const Abiturient& other) {
	name = other.name;
	age = other.age;
	Number_of_points = other.Number_of_points;
	speciality = other.speciality;
}

Abiturient& Abiturient::operator =(const Abiturient& other) {
	if (&other == this)
		return *this;
	name = other.name;
	age = other.age;
	Number_of_points = other.Number_of_points;
	speciality = other.speciality;
	return *this;
}

void Abiturient::Show() {
	cout << "Name: " << name;
	cout << "\nAge: " << age;
	cout << "\nNumber of points: " << Number_of_points;
	cout << "\nSpeciality: " << speciality;
	cout << "\n";
}
void Abiturient::Input() {
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
	cout << "Number of points: ";
	cin >> Number_of_points;
	cout << "Speciality: ";
	cin >> speciality;
	cout << "\n";
}