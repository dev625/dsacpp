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
    int n;
    cin >> n;
    vi V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    vi dp(n);
    dp[0] = 0;
    dp[1] = abs(V[1] - V[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(V[i] - V[i - 1]), dp[i - 2] + abs(V[i] - V[i - 2]));
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
