#include <iostream>
#include <string>
using namespace std;

struct MyClass
{
private:
	string str;
public:
	void Set_Str(string str) {
		this->str = str;
	}

	void Show_Str() {
		cout << this->str << endl;
	}

	MyClass(string str) {
		this->str = str;
	}
};

int main()
{
	MyClass item("This is first item");	

	item.Show_Str();

	item.Set_Str("No, no, no, THIS is first item");

	item.Show_Str();

	system("pause");
	return 0;
}