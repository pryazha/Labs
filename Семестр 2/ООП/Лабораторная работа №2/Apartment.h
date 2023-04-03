#include <iostream>
#include <string>
using namespace std;

class Apartment {
	string adress;
	double area;
	int number_of_rooms;
public:
	Apartment(); // Конструктор без параметров
	Apartment(string, double, int); // Конструктор с параметрами
	Apartment(const Apartment&); // Конструктор копирования
	~Apartment(); // Деструктор
	string get_adress(); // Селектор
	void set_adress(string); // Модификатор
	double get_area(); // Селектор
	void set_area(double); // Модификатор
	int get_number_of_rooms(); // Селектор
	void set_number_of_rooms(int); // Модификатор
	void show(); // Просмотр атрибутов
};