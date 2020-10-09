/*This works only for Directed Acyclic Graphs.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e, x, y;
    cin >> v >> e;
    vector<int> inDegree(v, 0);
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        //there is a directed edge from x to y
        adj[x].push_back(y);
        inDegree[y]++;
    }
    queue<int> Q;
    //We add all the vertices with 0 indegree to the queue;
    for (int i = 0; i < v; i++)
    {
        if (inDegree[i] == 0)
            Q.push(i);
    }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        cout << u << " ";
        for (auto x : adj[u])
        {
            inDegree[x]--;
            if (inDegree[x] == 0)
                Q.push(x);
        }
    }
}