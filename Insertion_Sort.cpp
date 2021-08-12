#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int val = a[i];
        int hole = i - 1;
        while (hole >= 0 && a[hole] > val)
        {
            a[hole + 1] = a[hole];
            hole--;
        }
        a[hole + 1] = val;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    insertion_sort(a);
    for (auto &x : a)
    {
        cout << x << "\n";
    }
}