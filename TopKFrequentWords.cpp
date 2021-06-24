#include <bits/stdc++.h>
using namespace std;

vector<string> topkfreq(vector<string> &words, int k)
{
    unordered_map<string, int> m;
    for (auto &x : words)
        m[x]++;
    auto comp = [&](const pair<string, int> &a, const pair<string, int> &b)
    {
        if (a.second == b.second)
            return a < b;
        else
            return a.second > b.second;
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> q(comp);
    for (auto &x : m)
    {
        q.emplace(x.first, x.second);
        if (q.size() > k)
            q.pop();
    }
    vector<string> ans;
    while (!q.empty())
    {
        ans.push_back(q.top().first);
        q.pop();
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the number of words and k value: \n";
    cin >> n >> k;
    cin.ignore(32767, '\n');
    vector<string> words(n);
    cout << "Enter the words: \n";
    for (auto &x : words)
        cin >> x;
    vector<string> ans = topkfreq(words, k);
    cout << "Top K Frequent Words sorted in lexographical order are :\n";
    for (auto &x : ans)
        cout << x << "\n";
}