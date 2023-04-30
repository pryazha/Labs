#include "Abiturient.cpp"

int main() {
	Person *A = new Person;
	A->Input();
	A->Show();

	Abiturient *B = new Abiturient;
	B->Input();
	B->Show();
	return 0;
}