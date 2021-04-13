#include <bits/stdc++.h>
using namespace std;

void printvector(const vector<vector<int>> &V, const string &s1, const string &s2)
{
    int m = V.size();
    int n = V[0].size();
    cout << "    ";
    for (int i = 0; i < n; i++)
    {
        cout << s2[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++)
    {
        if (i == 0)
            cout << "  ";
        if (i != 0)
            cout << s1[i - 1] << " ";
        for (int j = 0; j < n; j++)
        {
            cout << V[i][j] << " ";
        }
        cout << "\n";
    }
}

string lcstring(const string &s1, const string &s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] != s2[j - 1])
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
    }
    printvector(dp, s1, s2);
    int max_len{0}, ik{-1}, jk{-1};
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (dp[i][j] > max_len)
            {
                ik = i;
                jk = j;
                max_len = dp[i][j];
            }
        }
    }
    string ans = "";
    while (ik > 0 && jk > 0 && dp[ik][jk] != 0)
    {
        ans += s1[ik - 1];
        ik--;
        jk--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s1, s2;
    s1 = "aacabdkacaa";
    s2 = s1;
    reverse(s1.begin(), s1.end());
    string ans = lcstring(s1, s2);
    cout << ans;
}