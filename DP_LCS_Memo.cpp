#include <bits/stdc++.h>
using namespace std;
//Assuming input strings have max size 100
vector<vector<int>> dp(101, vector<int>(101, -1));

int lcs(const string &s1, const string &s2, int m, int n)
{
    if (dp[m][n] != -1)
        return dp[m][n];
    if (m == 0 || n == 0)
        return 0;
    else
    {
        if (s1[m - 1] == s2[n - 1])
            dp[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
        else
            dp[m][n] = max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
    }
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length(), n = s2.length();
    cout << lcs(s1, s2, m, n);
}