#include <iostream>
#include <ctime>
using namespace std;

void ShowArray(int* Arr, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

void CountSort(int* Array, int size, int MaxRange)
{
    int TempArr[MaxRange + 1];
    for (int i = 0; i < MaxRange + 1; i++)
        TempArr[i] = 0;

    for (int i = 0; i < size; i++)
        TempArr[Array[i]]++;

    int index = 0;
    for (int i = 0; i < MaxRange + 1; i++)
        while (TempArr[i]--)
            Array[index++] = i;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int SIZE = 10;
    int* Array = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
        Array[i] = rand() % 11;
    cout << "Массив до сотрировки: ";
    ShowArray(Array, SIZE);

    cout << "Метод сортировки подсчётом: ";
    CountSort(Array, SIZE, 10);
    ShowArray(Array, SIZE);

    delete[] Array;
    return 0;
}