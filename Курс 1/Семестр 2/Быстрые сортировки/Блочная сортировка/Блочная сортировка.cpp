#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

void ShowArray(float Arr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

void BucketSort(float Arr[], int size)
{
    vector<float> buckets[size];
 
    for (int i = 0; i < size; i++)
    {
        int bucketIndex = size * Arr[i];
        buckets[bucketIndex].push_back(Arr[i]);
    }
 
    for (int i = 0; i < size; i++)
        sort(buckets[i].begin(), buckets[i].end());

    int index = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < buckets[i].size(); j++, index++)
            Arr[index] = buckets[i][j];
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    const int SIZE = 10;
    float Array[SIZE] = { 0.23, 0.53, 0.13, 0.6, 0.43, 0.32, 0.54, 0.96, 0.65, 0.21 };
    cout << "Массив до сотрировки: ";
    ShowArray(Array, SIZE);

    cout << "Блочный метод сортировки: ";
    BucketSort(Array, SIZE);
    ShowArray(Array, SIZE);

    return 0;
}