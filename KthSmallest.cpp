#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &V, int l, int r)
{
    int x = V[l];
    int j = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (V[i] <= x)
        {
            j++;
            swap(V[i], V[j]);
        }
    }
    swap(V[l], V[j]);
    return j;
}

int KSmallest(vector<int> V, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = partition(V, l, r);
        //if position is same as k
        if (pos - l == k - 1)
            return V[pos];
        if (pos - l > k - 1)
            return KSmallest(V, l, pos - 1, k);
        return KSmallest(V, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> n;
        vector<int> V(n);
        for (int i = 0; i < n; i++)
            cin >> V[i];
        cin >> k;
        cout << KSmallest(V, 0, n - 1, k) << "\n";
    }
}