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

	int p = 2, q = 7;
	cout << "Введите индекс начального элемента массива: " << p << endl;
	cout << "Введите индекс конечного элемента массива: " << q << endl;

	int j = 0;
	for (int i = p; i <= q / 2 + 1; i++)
	{
		int temp = Arr[i];
		Arr[i] = Arr[q - j];
		Arr[q - j] = temp;
		j++;
	}

	cout << "Конечный массив: ";
	ShowArray(Arr, SIZE);

	return 0;
}