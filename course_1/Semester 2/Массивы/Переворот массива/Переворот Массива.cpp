#include <iostream>
using namespace std;

void ShowArray(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	const int SIZE = 10;
	int Arr[SIZE] = { 5, 2, 6, 3, 8, 1, 4, 9, 0, 7 };

	cout << "Исходный массив: ";
	ShowArray(Arr, SIZE);

	for (int i = 0; i < SIZE / 2; i++)
	{
		int temp = Arr[i];
		Arr[i] = Arr[SIZE - i - 1];
		Arr[SIZE - i - 1] = temp;
	}

	cout << "Конечный массив: ";
	ShowArray(Arr, SIZE);

	return 0;
}