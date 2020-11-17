#include <bits/stdc++.h>
using namespace std;

//O(n^2) Approach
int minimumJumps(int arr[], int n)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        bool flag = true;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] != 0 && arr[j] >= i - j)
            {
                flag = false;
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        if (flag == true)
            return -1;
    }
    return dp[n - 1];
}

//O(n) approach
int minimumJumpsGRD(int arr[], int n)
{
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    //stores the maximal reachable index in the array
    int maxReach = arr[0];
    //stores the number of steps that we can still take
    int step = arr[0];
    //stores the number of jumps necessary to reach that maximal
    //reachable position
    int jump = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jump;
        //updating maxreach
        maxReach = max(maxReach, i + arr[i]);
        //we use a step to get to the current index
        step--;
        //if no more steps remaining then we must've used
        //a jump, therefore increase jump
        if (step == 0)
        {
            jump++;
            if (i >= maxReach)
                return -1;
            step = maxReach - i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = 11;
    cout << minimumJumpsGRD(arr, n);
}