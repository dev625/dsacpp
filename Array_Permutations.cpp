#include <bits/stdc++.h>
using namespace std;

void backtrack(int curr, vector<int> &a, vector<vector<int>> &ans)
{
    if (curr == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = curr; i < a.size(); i++)
    {
        swap(a[i], a[curr]);
        backtrack(curr + 1, a, ans);
        swap(a[i], a[curr]);
    }
}

vector<vector<int>> all_permutations(vector<int> &a)
{
    vector<vector<int>> ans;
    backtrack(0, a, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> ans = all_permutations(a);
    for (auto &x : ans)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}