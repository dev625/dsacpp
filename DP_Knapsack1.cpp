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
    //Goal : Maximum Value that we can take //there is limited supply of items here
    ll n, w;
    cin >> n >> w;
    vector<ll> Weights(n), Vals(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> Weights[i];
        cin >> Vals[i];
    }
    ll dp[n + 1][w + 1];
    //dp[i][j] = maximum value that we can collect
    //with i tems with max capacity j
    for (ll i = 0; i <= w; i++)
        dp[0][i] = 0; //if no items then val = 0;
    for (ll i = 0; i <= n; i++)
        dp[i][0] = 0; //if capacity is 0 then again val = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= w; j++)
        {
            if (Weights[i - 1] > j) //if the current weight is greater than capacity then just take less items
                dp[i][j] = dp[i - 1][j];
            else //else choose between the value of including that item and choosing from the rest vs just choosing from the rest
                dp[i][j] = max(Vals[i - 1] + dp[i - 1][j - Weights[i - 1]], dp[i - 1][j]);
        }
    }
    cout << dp[n][w];
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
