/*
Author : Devesh Lohumi
You are your only limit!
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
constexpr long long int MOD = 1e9 + 7;
#define pb push_back
#define IGNORE cin.ignore(32767, '\n')
#define ppb pob_back
#define pf push_front
#define ppf pop_front
#define fr first
#define sc second
#define vi vector<int>
#define vll vector<long long int>
#define pii pair<int, int>
int countWays(int n)
{
    //to write n as 1......n-1
    vector<vector<int>> dp(n + 1, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (j <= i)
                dp[i][j] += dp[i - j][j];
        }
    }
    return dp[n][n - 1];
}

void solve()
{
    int n;
    cin >> n;
    int ans = countWays(n);
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t{1};
    while (t--)
    {
        solve();
    }
}
