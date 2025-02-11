#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; //size of left array
    int n2 = r - m;     //size of right array
    //creating temporary arrays;
    vector<int> L(n1), R(n2);
    /*Copying data to temp arrays*/
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; //initial index of first subarray
    j = 0; //initial index of second subarray
    k = l; //initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    //copy the remaining elements of L[],if any
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void MergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        //this gives the middle index

        /*If the array size is even then m is the last index 
          of the first half of the array.
          
          If the array size is odd then the left half is the
          larger half and m is the last index of the
          first half of the array .*/
        MergeSort(arr, l, m);     //Recursively Sort First Half
        MergeSort(arr, m + 1, r); //Recursively Sort Second Half
        Merge(arr, l, m, r);      //Merge The Two Halves
    }
}

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int size;
    cout << "Enter the number of elements : \n";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter the unsorted elements : \n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    MergeSort(arr, 0, size - 1);
    cout << "Sorted Array is : \n";
    printArray(arr);
}