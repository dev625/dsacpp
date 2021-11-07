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

bool check(int arr[], int n, ll mid, int k)
{
    ll sum = mid;
    int i = 0, painters = 1;
    while (i < n)
    {
        if (sum - arr[i] >= 0)
        {
            sum -= arr[i];
            i++;
        }
        else
        {
            painters++;
            sum = mid;
        }
        if (painters > k)
            return false;
    }
    return true;
}

long long minTime(int arr[], int n, int k)
{
    ll low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
        low = max(low, static_cast<ll>(arr[i]));
        high += arr[i];
    }
    ll res = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(arr, n, mid, k))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

void solve()
{
    int arr[] = {10, 20, 30, 40};
    cout << minTime(arr, 4, 2) << "\n";
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
