#include <bits/stdc++.h>
using namespace std;
//assuming max input is 100
vector<long long int> dp(101, -1);

long long int fibo(long long int n)
{
    if (dp[n] == -1)
    {
        long long int res;
        if (n == 0 || n == 1)
            res = n;
        else
            res = fibo(n - 1) + fibo(n - 2);
        dp[n] = res;
    }
    return dp[n];
}

int main()
{
    long long int n;
    cin >> n;
    long long int ans = fibo(n);
    cout << ans << "\n";
}