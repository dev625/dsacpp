#include <bits/stdc++.h>
using namespace std;

int binsearch(vector<int> &a, int ele)
{
    int n = a.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == ele)
            return mid;
        else if (a[mid] < ele)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l; //returns the position it should exist in the sorted array
}

int main()
{
    int n;
    cout << "Enter the number of array elements :\n";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the array elements in sorted order :\n";
    for (auto &x : a)
        cin >> x;
    while (1)
    {
        int ele;
        cout << "Enter the element you want to search for :\n";
        cin >> ele;
        int idx = binsearch(a, ele);
        cout << "The position/to be position of ele is " << binsearch(a, ele);
    }
}