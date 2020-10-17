/*In the recursion tree if there is an 
edge from a descendant to an ancestor and that ancestor
is currently active in recursion then we say that there
is a cycle.

Property : A directed graph has a cycle if and only if
its DFS traversal reveals a back-edge.
*/
#include <bits/stdc++.h>
using namespace std;

bool dfs_check(vector<int> adj[], int s, bool visited[], bool rec[])
{
    visited[s] = true;
    rec[s] = true;
    for (auto x : adj[s])
    {
        if (visited[x] == false && dfs_check(adj, x, visited, rec) == true)
            return true;
        else if (rec[x] == true)
            return true;
    }
    rec[s] = false;
    return false;
}

bool hasCycle(vector<int> adj[], int v)
{
    bool visited[v];
    bool rec[v];
    memset(visited, false, v);
    memset(visited, false, v);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (dfs_check(adj, i, visited, rec) == true)
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
    cout << hasCycle(g, v) << "\n";
}