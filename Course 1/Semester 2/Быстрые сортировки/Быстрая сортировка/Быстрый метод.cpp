#include <iostream>
#include <ctime>
using namespace std;

void ShowArray(int* Arr, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

void quickSort(int* array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;
    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int SIZE = 10;
    int* Array = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
        Array[i] = rand() % 10 - 10;
    cout << "Массив до сотрировки: ";
    ShowArray(Array, SIZE);

    cout << "Метод быстрой сортировки: ";
    quickSort(Array, 0, SIZE - 1);
    ShowArray(Array, SIZE);

    delete[] Array;
    return 0;
}