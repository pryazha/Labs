#include "Person.cpp"

class Abiturient : public Person {
public:
	Abiturient();
	Abiturient(string, int, int, string);
	~Abiturient();
	Abiturient(const Abiturient&);

	void Show();
	void Input();

	int Get_Number_of_points() {
		return Number_of_points;
	}
	string Get_speciality() {
		return speciality;
	}

	void Set_Number_of_points(int np) {
		Number_of_points = np;
	}
	void Set_speciality(string s) {
		speciality = s;
	}

	Abiturient& operator =(const Abiturient&);
protected:
	int Number_of_points;
	string speciality;
};