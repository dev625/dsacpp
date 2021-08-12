/*
Author : Devesh Lohumi
लहरों से डर कर नौका पार नहीं होती,
कोशिश करने वालों की हार नहीं होती।
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr long long int MOD = 1000000007;
#define IGNORE cin.ignore(32767, '\n')
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fr first
#define sc second
#define vi vector<int>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pll pair<long long, long long>

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    ll sum = 0;
    for (auto &x : a)
    {
        cin >> x;
        sum += x;
    }
    vector<vll> dp(n + 1, vll(sum + 1, 0));
    for (ll i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    ll diff = INT64_MAX;
    for (int j = 0; j <= sum; j++)
    {
        if (dp[n][j] > 0)
            diff = min(diff, abs(sum - 2 * j));
    }
    cout << diff;
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
