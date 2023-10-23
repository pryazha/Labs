#include "Apartment.h"
#include <iostream>
#include <string>
using namespace std;

Apartment::Apartment() {
	adress = "";
	area = 0;
	number_of_rooms = 0;
	cout << "Конструктор без параметров для объекта: " << this << endl;
}

Apartment::Apartment(string adress, double area, int number_of_rooms) {
	this->adress = adress;
	this->area = area;
	this->number_of_rooms = number_of_rooms;
	cout << "Конструктор с параметрами для объекта: " << this << endl;
}

Apartment::Apartment(const Apartment &Other) {
	adress = Other.adress;
	area = Other.area;
	number_of_rooms = Other.number_of_rooms;
	cout << "Конструктор копирования для объекта: " << this << endl;
}

Apartment::~Apartment() {
	cout << "Деструктор для объекта: " << this << endl;
}

// Селекторы
string Apartment::get_adress() {
	return adress;
}

double Apartment::get_area() {
	return area;
}

int Apartment::get_number_of_rooms() {
	return number_of_rooms;
}

//Модификаторы
void Apartment::set_adress(string adress) {
	this->adress = adress;
}

void Apartment::set_area(double area) {
	this->area = area;
}

void Apartment::set_number_of_rooms(int number_of_rooms) {
	this->number_of_rooms = number_of_rooms;
}

void Apartment::show() {
	cout << "Адрес: " << adress << endl;
	cout << "Площадь: " << area << endl;
	cout << "Количество комнат: " << number_of_rooms << endl;
}