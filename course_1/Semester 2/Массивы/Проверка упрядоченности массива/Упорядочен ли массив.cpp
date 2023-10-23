#include <iostream>
using namespace std;

void ShowArray(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	const int size = 5;
	int array[size] = { 2, 7, 5, 7, 8 };

	bool flag = true;

	for (int i = 0; (i < size - 1) && flag; i++)
		flag = (array[i] < array[i + 1]); 

	if (flag)
		cout << "Массив упорядочен: ";
	else
		cout << "Массив не упорядочен: ";

	ShowArray(array, size);

	return 0;
}