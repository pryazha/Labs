#include <iostream>
#include <ctime>
using namespace std;

void ShowArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void QuickSort(int* arr, int first, int last)
{
	int i = first;
	int j = last;
	int pivot = arr[(first + last) / 2];
	
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i <= j)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

			i++;
			j--;
		}

		if (i < last)
			QuickSort(arr, i, last);
		if (j > first)
			QuickSort(arr, first, j);
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
	QuickSort(Array, 0, size - 1);
	ShowArray(Array, size);

	return 0;
}