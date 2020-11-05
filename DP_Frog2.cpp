#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
constexpr long long int MOD = 1e9 + 7;
#define pb push_back
#define ppb pob_back
#define pf push_front
#define ppf pop_front
#define fr first
#define sc second
#define vi vector<int>
#define pii pair<int, int>

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> V(n), dp(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    dp[0] = 0;
    dp[1] = abs(V[1] - V[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = INT_MAX;
        int leftmost = max(i - k, 0);
        for (int j = leftmost; j < i; j++)
        {
            dp[i] = min(dp[i], dp[j] + abs(V[i] - V[j]));
        }
    }
    cout << dp[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}
