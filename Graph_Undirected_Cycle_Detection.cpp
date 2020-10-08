#include <bits/stdc++.h>
using namespace std;

bool DFS_Check(vector<int> g[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (auto x : g[s])
    {
        if (visited[x] == false)
        {
            if (DFS_Check(g, x, visited, s) == true)
                return true;
        }
        else if (x != parent)
            return true;
    }
    return false;
}

bool hascycle(vector<int> g[], int v)
{
    bool visited[v];
    memset(visited, false, v);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (DFS_Check(g, i, visited, -1) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    int v, e, foo, bar;
    cin >> v >> e;
    vector<int> g[v];
    for (int i = 0; i < e; i++)
    {
        cin >> foo >> bar;
        g[foo].push_back(bar);
        g[bar].push_back(foo);
    }
    cout << hascycle(g, v) << "\n";
}