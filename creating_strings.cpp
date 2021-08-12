#include <bits/stdc++.h>
using namespace std;

void backtrack(const string &s, string &temp, int n, vector<bool> &freq, vector<string> &ans)
{
    if (temp.size() == n)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && s[i] == s[i - 1] && freq[i - 1] == 1)
            continue;
        if (freq[i] == false)
        {
            temp += s[i];
            freq[i] = true;
            backtrack(s, temp, n, freq, ans);
            temp.pop_back();
            freq[i] = false;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string temp = "";
    vector<bool> freq(n, false);
    sort(s.begin(), s.end());
    vector<string> ans;
    backtrack(s, temp, n, freq, ans);
    cout << ans.size() << "\n";
    for (auto &x : ans)
        cout << x << "\n";
}