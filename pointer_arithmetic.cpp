#include <bits/stdc++.h>
using namespace std;

int main()
{
    int val{7};
    int *ptr{&val};
    cout << ptr << "\n";
    cout << ptr + 1 << "\n";
    cout << ptr + 2 << "\n";
    cout << ptr + 3 << "\n";
    cout << "Pointer Arithmetic\n";
    int arr[]{9, 4, 11, 3, 4, 5};
    cout << arr << "\n";
    cout << arr[1] << "\n";
    cout << *(arr + 1) << "\n";
    for (int *ptr{arr}; ptr != arr + 6; ptr++)
        cout << *ptr << "\n";
}