#include <iostream>
using namespace std;

int RecursiveBinarySearch(int *arr, int ele, int l, int r)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == ele)
            return mid;
        else if (arr[mid] > ele)
            return RecursiveBinarySearch(arr, ele, l, mid - 1);
        else
            return RecursiveBinarySearch(arr, ele, mid + 1, r);
    }
    return -1;
}

int main()
{
    int i, len, ele;
    cout << "Enter the length of array:\n";
    cin >> len;
    int *arr = new int[len];
    cout << "Enter the elements of the array in sorted order: \n";
    for (i = 0; i < len; i++)
        cin >> arr[i];
    cout << "Which element do you want to search for ?\n";
    cin >> ele;
    if (RecursiveBinarySearch(arr, ele, 0, len - 1) == -1)
        cout << "Element " << ele << " not present in the array.\n";
    else
        cout << "Element " << ele << " found at index : " << RecursiveBinarySearch(arr, ele, 0, len - 1) << "\n";
}