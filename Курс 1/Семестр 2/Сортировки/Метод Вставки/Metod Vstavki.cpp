#include <iostream>
#include <ctime>
using namespace std;

void FillArray(int* arr, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % 10;
}

void ShowArray(int* arr, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void SortArray(int* arr, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int SIZE = 5;
	int* Array = new int[SIZE];
	FillArray(Array, SIZE);

	cout << "Массив до сортировки: " << endl;
	ShowArray(Array, SIZE);

	cout << "Массив после сортировки (метод вставки): " << endl;
	SortArray(Array, SIZE);
	ShowArray(Array, SIZE);

	system("pause");

	delete[] Array;

	return 0;
}