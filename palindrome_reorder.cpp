#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> m;
    for (auto &x : s)
        m[x]++;
    int oddcount = 0;
    char oddchar = 'A';
    for (auto &x : m)
    {
        if (x.second % 2 == 1)
        {
            oddchar = x.first;
            oddcount++;
        }
    }
    if (oddcount > 1)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        string ans = "";
        for (auto &x : m)
        {
            if (x.first != oddchar)
            {
                for (int i = 0; i < x.second / 2; i++)
                    ans += x.first;
            }
        }
        int len = ans.size();
        for (int i = 0; i < m[oddchar]; i++)
            ans += oddchar;
        for (int i = len - 1; i >= 0; i--)
            ans += ans[i];
        cout << ans << "\n";
    }
}