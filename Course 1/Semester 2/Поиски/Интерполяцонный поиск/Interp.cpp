#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int interpolationSearch(int arr[], int size, int value)
{
	int left = 0;
	int right = size - 1;
	int mid;

	while (left <= right && value >= arr[left] && value <= arr[right])
	{
		mid = left + (((double)(right - left) / (arr[right] - arr[left])) * (value - arr[left]));

		if (arr[mid] == value)
			return mid;
		if (value > arr[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	srand(time(NULL));
	int size = 10, value;

	int Array[size] = { 0, 3, 5, 5, 6, 8, 10, 15, 16, 20 };
	cout << "Array: ";
	for (int i = 0; i < size; i++)
		cout << Array[i] << " ";
	cout << endl;

	cout << "Enter a search value: ";
	cin >> value;

	cout << "Value found at index: " << interpolationSearch(Array, size, value);

	return 0;
}