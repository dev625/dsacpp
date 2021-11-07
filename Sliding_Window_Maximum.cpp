#include <bits/stdc++.h>
using namespace std;

/*
Monotonic Queue : Deque with property such that elements
from head to tail are in decreasing order.

Modify push : Before we push anything, first pop everything smaller
than it from the deque.



*/

vector<int> sliding_window_max(const vector<int> &a, int k)
{
    int n = a.size();
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        //Remove the first element if it is out of window
        if (!q.empty() && q.front() == i - k)
            q.pop_front();
        //Remove all elements lesser than current
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        //The head of the deque always contains the max element
        if (i >= k - 1)
            ans.push_back(a[q.front()]);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> ans = sliding_window_max(a, k);
    for (auto &x : ans)
        cout << x << " ";
    cout << "\n";
}