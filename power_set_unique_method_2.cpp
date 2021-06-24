#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &nums, int idx, vector<int> &temp, vector<vector<int>> &ans)
{
    ans.push_back(temp);
    for (int i = idx; i < nums.size(); i++)
    {
        temp.push_back(nums[i]);
        backtrack(nums, i + 1, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> power_set(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp;
    vector<vector<int>> ans;
    backtrack(arr, 0, temp, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    vector<vector<int>> ans = power_set(arr);
    for (auto &x : ans)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}