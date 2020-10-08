#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i;
        if (adj[i].size() > 0)
            cout << "-> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j];
            if (j != adj[i].size() - 1)
                cout << "-> ";
        }
        cout << "\n";
    }
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
    print(g, v);
}