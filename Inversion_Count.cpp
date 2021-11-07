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

ll merge(vector<ll> &a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<ll> L(n1), R(n2);
    int k = left;
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[mid + 1 + i];
    ll count = 0;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            count += (n1 - i);
            a[k++] = R[j++];
        }
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
    return count;
}

ll count(vector<ll> &a, int left, int right)
{
    ll ans = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        ans += count(a, left, mid);
        ans += count(a, mid + 1, right);
        ans += merge(a, left, mid, right);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (auto &x : a)
        cin >> x;
    ll ans = -1;
    ans = count(a, 0, n - 1);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t{1};
    cin >> t;
    while (t--)
    {
        solve();
    }
}
