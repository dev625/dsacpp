#include <bits/stdc++.h>
using namespace std;

/*
For an array consisting of n unique integers we have 2^n unique subsets, so for every element
we basically either pick it or not pick it. In this method we create pick or not pick arrays 
with the help of std::bitset for every possible permutation and iterate through them generating our subsets.

TC : O(2^n * (n+n)) second n for copying temp to arr;
SC : O(n)
*/

vector<vector<int>> power_set(vector<int> arr)
{
    int n = arr.size();
    int limit = pow(2, n);
    vector<vector<int>> ans;
    for (int i = 0; i < limit; i++)
    {
        //assuming n<=32 otherwise create a larger bitset
        //we need to specify bitset size at compile time
        vector<int> temp;
        bitset<32> m(i);
        for (int j = 0; j < n; j++)
        {
            if (m[j] == 1)
                temp.push_back(arr[j]);
        }
        ans.push_back(temp);
    }
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