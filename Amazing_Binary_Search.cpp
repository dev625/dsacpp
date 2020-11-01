#include <bits/stdc++.h>
using namespace std;

int indexofzero(const vector<int> &V, int l, int r)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        //If mid is corner and is 0
        if ((mid == l || mid == r) && V[mid] == 0)
            return mid;
        //If a 1 is found
        if (V[mid] == 1)
            return indexofzero(V, mid + 1, r);
        //If a zero is found with left as 1;
        if (V[mid] == 0 && V[mid - 1] == 1)
            return mid;
        //If a zero is found with left as zero
        if (V[mid] == 0 && V[mid - 1] == 0)
            return indexofzero(V, l, mid - 1);
    }
    return -1;
}

int countones(const vector<int> &V)
{
    int l = 0;
    int r = V.size();
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (V[mid] == 1)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main()
{
    int n;
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    cout << countones(V;
}
