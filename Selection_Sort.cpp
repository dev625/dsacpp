#include <iostream>
using namespace std;

void SelectionSort(int arr[], int l)
{
    int i, j, min_id;
    for (i = 0; i < l - 1; i++)
    //after ith iteration the ith element is in its correct position
    {
        min_id = i;
        //assume the first element as the minimum element
        for (j = i + 1; j < l; j++)
        {
            if (arr[j] < arr[min_id])
                min_id = j;
        }
        swap(arr[i], arr[min_id]);
    }
}

void printarray(int arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {4, 8, 2, 9, 1, 99, 223, 34, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    printarray(arr, size);
    SelectionSort(arr, size);
    printarray(arr, size);
}