#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5]{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        cout << &arr[i] << "\n";
    cout << "The array decays to a pointer holding address : " << arr << "\n ";
}