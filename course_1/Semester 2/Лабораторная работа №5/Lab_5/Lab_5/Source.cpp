#include <iostream>
#include <ctime>
using namespace std;

void displayArray(int** Array, int rows, int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Array[i][j] = rand() % 10;
			cout << Array[i][j] << " ";
		}
		cout << endl;
	}
}

double SrednArifm(int** Array, int rows, int cols)
{
	double sum = 0;
	for (int i = 0; i < rows; i++)
		sum += Array[i][cols];
	return sum / rows;
}

void Solution(int** Array, int rows, int cols)
{
	cout << "�������: " << 1 << ", ������� �����.: " << SrednArifm(Array, rows, 0) << endl;
	for (int i = 1; i < cols; i++)
	{
		double SrednAr = SrednArifm(Array, rows, i - 1);
		int sum = 0;
		for (int j = 0; j < rows; j++)
		{
			if (Array[j][i] > SrednAr)
				sum++;
		}
		cout << "C������: " << i + 1 << ", ��. �����. ����. �������: " << SrednAr << " - ���-�� ��. ����������� ���: " << sum << endl;

	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int rows, cols;

	cout << "������� ���-�� �����: ";
	cin >> rows;
	cout << "������� ���-�� ��������: ";
	cin >> cols;

	int** Array = new int* [rows];

	for (int i = 0; i < rows; i++)
		Array[i] = new int[cols];

	displayArray(Array, rows, cols);

	Solution(Array, rows, cols);

	for (int i = 0; i < rows; i++)
		delete[] Array[i];

	delete[] Array;

	return 0;
}