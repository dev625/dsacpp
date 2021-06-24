#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &nums, int idx, vector<int> &temp, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[idx]);
    backtrack(nums, idx + 1, temp, ans);
    temp.pop_back();
    backtrack(nums, idx + 1, temp, ans);
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