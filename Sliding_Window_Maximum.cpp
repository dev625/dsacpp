#include <bits/stdc++.h>
using namespace std;

vector<int> sliding_window_max(const vector<int> &a, int k)
{
    vector<int> ans;
    int n = a.size();
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && i - q.front() >= k)
            q.pop_front(); //discard out of range elements
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back(); //remove all elements lesser than current
        q.push_back(i);
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