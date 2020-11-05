#include <bits/stdc++.h>
using namespace std;
vector<int> dp(101, -1);
int n;
int maxam(vector<int> &V, int k)
{
    if (k > n - 1)
        return 0;
    if (dp[k] == -1)
    {
        int ans = 0;
        ans = max(V[k] + maxam(V, k + 2), maxam(V, k + 1));
        dp[k] = ans;
    }
    return dp[k];
}
int main()
{
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++)
        cin >> V[i];
    int ans = maxam(V, 0);
    cout << ans << "\n";
}
