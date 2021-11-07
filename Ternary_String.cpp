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
    string s;
    cin >> s;
    vector<pair<char, int>> a;
    for (auto &x : s)
    {
        if (a.empty() || x != a.back().first)
            a.push_back({x, 1});
        else
            a.back().second++;
    }
    int len = INT_MAX;
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (a[i - 1].first != a[i + 1].first)
            len = min(len, 2 + a[i].second);
    }
    (len == INT_MAX) ? (cout << 0 << "\n") : (cout << len << "\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t{1};
    cin >> t;
    IGNORE;
    while (t--)
    {
        solve();
    }
}
