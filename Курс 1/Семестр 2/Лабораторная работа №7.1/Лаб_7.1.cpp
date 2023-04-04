#include <iostream>
#include <ctime>
using namespace std;

int NumberOfElements(int* Array, int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
		if (Array[i] % 2 != 0)
			counter++;
	return counter;
}

int NumberOfElements(char String[])
{
	int counter = 0;
	int numberOfWords = 1;
	while (String[counter] != '\0')
	{
		if (String[counter] == ' ')
			numberOfWords++;
		counter++;
	}
	return numberOfWords;
}

int main()
{
	srand(time(NULL));
	int size = 10;
	int* Array = new int[size];
	for (int i = 0; i < size; i++)
	{
		Array[i] = rand() % 10;
		cout << Array[i] << " ";
	}
	cout << endl;

	char String[] = "Hello This is Lab a #7.";
	cout << String << endl;

	cout << "Number of odd elements (Array): " << NumberOfElements(Array, size) << endl;
	cout << "Number of words (String): " << NumberOfElements(String) << endl;

	delete[] Array;

	return 0;
}