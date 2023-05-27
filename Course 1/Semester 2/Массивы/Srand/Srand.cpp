#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));

	const int SIZE = 5;
	int Array[SIZE]{};

	for (int i = 0; i < SIZE; i++)
	{
		Array[i] = rand() % 10;
		cout << Array[i] << " ";
	}
	cout << endl;

	return 0;
}