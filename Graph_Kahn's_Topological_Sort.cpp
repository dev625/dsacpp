/*This works only for Directed Acyclic Graphs.

Fact : A DAG has at least one vertex with in-degree 0
and one vertex with out-degree 0.

A topological sort is a linear ordering of the vertices
of a DAG such that for every directed edge uv from vertex u
to vertex v, u comes before v in the ordering.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e, x, y;
    cin >> v >> e;
    vector<int> inDegree(v, 0);
    vector<int> adj[v];
    vector<int> result;
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
    int cnt{0};
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        result.push_back(u);
        for (auto x : adj[u])
        {
            inDegree[x]--;
            if (inDegree[x] == 0)
                Q.push(x);
        }
        cnt++;
    }
    if (cnt != v)
    {
        cout << "There exists a cycle in the graph.\n";
    }
    else
    {
        for (auto x : result)
            cout << x << " ";
    }
}