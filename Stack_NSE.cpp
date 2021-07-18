#include <bits/stdc++.h>
using namespace std;

vector<int> nge(const vector<int> &a)
{
    int n = a.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= a[i])
            s.pop();
        (s.empty()) ? (ans[i] = -1) : (ans[i] = s.top());
        s.push(a[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> ans = nge(a);
    for (auto &X : ans)
        cout << X << "  ";
    return 0;
}