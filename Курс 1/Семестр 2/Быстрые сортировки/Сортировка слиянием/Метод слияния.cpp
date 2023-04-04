#include <iostream>
#include <ctime>
using namespace std;

void ShowArray(int* Arr, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

void Merge(int* Arr, int first, int last)
{
    int middle, start, final, j;
    int* mas = new int[100];
    middle = (first + last) / 2; 
    start = first;
    final = middle + 1;

    for (j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (Arr[start] < Arr[final])))
        {
            mas[j] = Arr[start];
            start++;
        }
        else
        {
            mas[j] = Arr[final];
            final++;
        }

    for (j = first; j <= last; j++) 
        Arr[j] = mas[j];

    delete[] mas;
}

void MergeSort(int* Arr, int first, int last)
{
    if (first < last)
    {
        MergeSort(Arr, first, (first + last) / 2);
        MergeSort(Arr, (first + last) / 2 + 1, last);
        Merge(Arr, first, last);
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int SIZE = 10;
    int* Array = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
        Array[i] = rand() % 10;
    cout << "Массив до сотрировки: ";
    ShowArray(Array, SIZE);

    cout << "Метод сортировки слиянием: ";
    MergeSort(Array, 0, SIZE - 1);
    ShowArray(Array, SIZE);

    delete[] Array;
    return 0;
}