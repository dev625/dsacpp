#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp{x};
    x = y;
    y = temp;
}

void MaxHeapify(int *arr, int n, int i)
{

    /*Heapify functions assume that both the left and right subtrees area maxheaps.*/
    int l = (2 * i) + 1; //following 0 based indexing
    int r = (2 * i) + 2;
    int largest;
    if (l <= n - 1 && arr[l] >= arr[i])
        largest = l;
    else
        largest = i;
    if (r <= n - 1 && arr[r] >= arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        MaxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(int *arr, int n)
{
    int i;
    int lastparent = (n / 2) - 1;
    for (i = lastparent; i >= 0; i--)
        MaxHeapify(arr, n, i);
}

void HeapSort(int *arr, int n)
{
    int heap_size = n;
    BuildMaxHeap(arr, n);
    for (int i = (n - 1); i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        heap_size--;
        MaxHeapify(arr, heap_size, 0);
    }
}

int main()
{
    int i, n;
    // cout << "Enter the size of the array : \n";
    // cin >> n;
    // int *arr = new int[n];
    // cout << "Enter the elements of the array :\n"; //5 20 19 14 16 18 17
    // for (i = 0; i < n; i++)
    //     cin >> arr[i];
    // cout << "The array after applying maxheap procedure is : \n";
    // MaxHeapify(arr, n, 0);
    // for (i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // //now code for demonstrating heap sort;
    // cout << "\nEnter the size of the array :\n";
    // cin >> n;
    // int *arr2 = new int[n];
    // cout << "Enter the elements of the array : \n"; // 1 2 3 4 5 6 7
    // for (i = 0; i < n; i++)
    //     cin >> arr2[i];
    // BuildMaxHeap(arr2, n);
    // cout << "The array after applying build max heap procedure is : \n";
    // for (i = 0; i < n; i++)
    //     cout << arr2[i] << " ";
    cout << "\nEnter the size of the array :\n";
    cin >> n;
    int *arr3 = new int[n];
    cout << "Enter the elements of the array :\n";
    for (i = 0; i < n; i++)
        cin >> arr3[i];
    HeapSort(arr3, n);
    cout << "The array after applying HeapSort Procedure is:\n";
    for (i = 0; i < n; i++)
        cout << arr3[i] << " ";
    cout << "\n";
}