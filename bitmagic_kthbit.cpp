/*
Author : Devesh Lohumi
You are your only limit!
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
constexpr long long int MOD = 1e9 + 7;
#define pb push_back
#define IGNORE cin.ignore(32767, '\n')
#define ppb pob_back
#define pf push_front
#define ppf pop_front
#define fr first
#define sc second
#define vi vector<int>
#define pii pair<int, int>

bool kthbit1(int n, int k)
{
    /*
    Left Shift method we basically shift the number to the left by k-1 bits
    adn check if its AND with n is 0 or not
    */
    if (n & (1 << (k - 1)))
        return true;
    return false;
}

bool kthbit2(int n, int k)
{
    /*Right Shift method,we basically get the kth bit to the 0th position
    by shifting it by k-1 bits to the right. If its AND with 1 is 1 then the kth
    bit is set, if its 0 then its not set*/
    if ((n >> (k - 1)) & 1)
        return true;
    return false;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    bool ans = kthbit2(n, k);
    cout << ans << "\n";
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
