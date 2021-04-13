#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>&a)
{
    int n = a.size();
    for(int i=1;i<n;i++)
    {
        int val = a[i];
        int hole = i;
        while(hole>0 && a[hole-1]>val)
        {
            a[hole] = a[hole-1];
            hole--;
        }
        a[hole] = val;
    }

}

int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &x : a)
    {
        cin >> x;
    }
    insertion_sort(a);
    for(auto &x : a)
    {
        cout << x << "\n";
    }

}