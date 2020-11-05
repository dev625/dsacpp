#include <bits/stdc++.h>
using namespace std;

int mincoins(vector<int> &coins, int amount, int n)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        //for every amount smaller than or equal to amount
        //we check the minimum number of coins required to make that amount
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX)
                    dp[i] = min(dp[i], sub_res + 1);
            }
        }
    }
    return dp[amount];
}

int main()
{
    int n;
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    int amount;
    cin >> amount;
    int ans = mincoins(V, amount, n - 1);
    if (ans != INT_MAX)
        cout << ans << "\n";
    else
        cout << -1 << "\n";
}