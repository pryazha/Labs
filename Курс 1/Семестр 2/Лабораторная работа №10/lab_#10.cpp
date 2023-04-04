#include <iostream>
#include <string>

using namespace std;

void fillArray(string* arr, int size)
{
	cout << "Enter array valuse: \n";
	for (int i = 0; i < size; i++)
		getline(cin, arr[i]);
}

void showArray(string* arr, int size)
{
	cout << "Array: " << endl;
	for (int i = 0; i < size; i++)
		cout << "Element " << i + 1 << ": " << arr[i] << "\n";
	cout << endl;
}

void deleteElements(string* arr, int &size)
{
	int NumberOfDel, k;
	cout << "Enter the element number from which the elements will be removed: ";
	cin >> NumberOfDel;
	cout << "Enter the number of items to remove: ";
	cin >> k;

	if (k >= size)
		k = size - NumberOfDel + 1;
	string* tempArr = new string[size - k];

	if (NumberOfDel < size && NumberOfDel != 1)
	{
		int i = 0;
		while (i < NumberOfDel - 1)
		{
			tempArr[i] = arr[i];
			i++;
		}
		int j = i;
		i += k;
		while (i < size)
		{
			tempArr[j] = arr[i];
			i++;
			j++;
		}		
	}

	if (NumberOfDel == 1)
	{
		int i = k, j = 0;
		for (i, j; i < size; i++, j++)
			tempArr[j] = arr[i];
	}

	if (NumberOfDel == size)
		for (int i = 0; i < size - 1; i++)
			tempArr[i] = arr[i];

	// delete[] arr;
	// arr = tempArr;
	// delete tempArr;
	// size = size - k;
	cout << "\nArray: \n";
	for (int i = 0; i < size - k; i++)
		cout << "Element " << i + 1 << ": " << tempArr[i] << "\n";

	delete[] tempArr;
}

int main()
{
	int size;
	cout << "Enter size of the Array: ";
	cin >> size;
	cin.get();

	string* StrArr = new string[size];
	fillArray(StrArr, size);
	showArray(StrArr, size);

	deleteElements(StrArr, size);

	delete[] StrArr;
	return 0;
}