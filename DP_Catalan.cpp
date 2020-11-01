#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;

vector<ll> arr(101, INT_MIN);

ll catalan(ll n)
{
    if (arr[n] == INT_MIN)
    {
        ll ans = 0;
        if (n <= 1)
            ans = 1;
        else
        {
            for (int i = 0; i < n; i++)
                ans += catalan(i) * catalan(n - i - 1);
        }
        arr[n] = ans;
    }
    return arr[n];
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << catalan(n) << "\n";
    }
}