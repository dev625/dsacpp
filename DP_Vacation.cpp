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
    vector<vector<int>> V(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> V[i][j];
        }
        if (i != 0)
        {
            V[i][0] += max(V[i - 1][1], V[i - 1][2]);
            V[i][1] += max(V[i - 1][0], V[i - 1][2]);
            V[i][2] += max(V[i - 1][1], V[i - 1][0]);
        }
    }
    cout << *max_element(V[n - 1].begin(), V[n - 1].end());
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
