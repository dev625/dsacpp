#include <bits/stdc++.h>
using namespace std;
//presumably works for both directed and undirected graphs , CONFIRM LATER!!!

void BFS(vector<int> adj[], int v, int s)
{
    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (auto x : adj[temp])
        {
            if (visited[x] == false)
            {
                dist[x] = dist[temp] + 1;
                visited[x] = true;
                Q.push(x);
            }
        }
    }
    for (auto x : dist)
        cout << x << " ";
}

int main()
{
    int v, e, x, y;
    vector<int> adj[v];
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    BFS(adj, v, 0);
}