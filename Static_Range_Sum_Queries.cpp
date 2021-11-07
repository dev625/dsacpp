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
    int n, q;
    cin >> n >> q;
    vll a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x == 0)
            cout << a[y] << "\n";
        else
            cout << a[y] - a[x - 1] << "\n";
    }
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
