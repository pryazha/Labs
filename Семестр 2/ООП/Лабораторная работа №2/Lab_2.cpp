#include "Apartment.cpp"
#include <iostream>
#include <string>
using namespace std;

Apartment make_apartment() {
	string adress;
	double area;
	int number_of_rooms;
	cout << "Введите адрес квартиры: ";
	cin >> adress;
	cout << "Введите площадь квартиры: ";
	cin >> area;
	cout << "Введите колество комнат в квартире: ";
	cin >> number_of_rooms;
	Apartment apart(adress, area, number_of_rooms);
	return apart;
}

void print_apartment(Apartment apart) {
	apart.show();
}

int main() {
	Apartment apartment_1; // Конструктор без параметров
	apartment_1.show();
	Apartment apartment_2("Адрес 2-ой квартиры", 32, 2); // Конструктор с параметрами
	apartment_2.show();
	Apartment apartment_3 = apartment_2; // Конструктор копирования
	apartment_3.set_adress("Адрес 3-ей квартиры");
	apartment_3.set_area(20.1);
	apartment_3.set_number_of_rooms(4);
	print_apartment(apartment_3);
	apartment_1 = make_apartment();
	apartment_1.show();
	return 0;
}