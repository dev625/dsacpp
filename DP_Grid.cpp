/*
Author : Devesh Lohumi
You only fail when you stop trying.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int MOD = 1000000007;
#define IGNORE cin.ignore(32767, '\n')
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fr first
#define sc second
#define vi vector<int>
#define vll vector<long long int>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pll pair<long long, long long>

void solve()
{
    int h, w;
    cin >> h >> w;
    IGNORE;
    vector<string> S(h);
    for (int i = 0; i < h; i++)
        cin >> S[i];
    vector<vector<int>> M(h, vector<int>(w, 0));
    if (S[0][0] == '#')
    {
        cout << 0;
        return;
    }
    M[0][0] = 1;
    for (int i = 1; i < h; i++)
    {
        if (S[i][0] == '#')
            M[i][0] = 0;
        else
            M[i][0] = M[i - 1][0];
    }
    for (int j = 1; j < w; j++)
    {
        if (S[0][j] == '#')
            M[0][j] = 0;
        else
            M[0][j] = M[0][j - 1];
    }
    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
        {
            if (S[i][j] == '#')
                M[i][j] = 0;
            else
                M[i][j] = (M[i - 1][j] + M[i][j - 1]) % MOD;
        }
    }
    cout << M[h - 1][w - 1];
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
