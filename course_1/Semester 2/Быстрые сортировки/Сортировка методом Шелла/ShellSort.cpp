#include <iostream>
#include <ctime>
using namespace std;

void ShowArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void ShellSort(int* arr, const int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
		for (int i = gap; i < size; i++)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
}

int main()
{
	srand(time(NULL));
	int size;
	cout << "Enter the size of the Array: ";
	cin >> size;

	int* Array = new int[size];
	for (int i = 0; i < size; i++)
		Array[i] = rand() % 11;

	cout << "Array before sorting: ";
	ShowArray(Array, size);

	cout << "Array after sorting: ";
	ShellSort(Array, size);
	ShowArray(Array, size);

	delete[] Array;
	return 0;
}