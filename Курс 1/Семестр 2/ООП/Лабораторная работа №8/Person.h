#include "Object.cpp"
#include <string>
#include <iostream>
using namespace std;

class Person : public Object {
public:
	Person();
	virtual ~Person();
	void Show();
	void Input();
	Person(string, int);
	Person(const Person&);

	string Get_name() {
		return name;
	}
	int Get_age() {
		return age;
	}

	void Set_name(string n) {
		name = n;
	}
	void Set_age(int a) {
		age = a;
	}

	Person& operator =(const Person&);
protected:
	string name;
	int age;
};