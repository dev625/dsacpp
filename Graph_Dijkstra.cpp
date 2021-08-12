#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> adj[], int v, int source)
{
    vector<int> distance(v, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int src = parent.second;
        for (auto &x : adj[src])
        {
            int node = x[0];
            int weight = x[1];
            if (distance[src] + weight < distance[node])
            {
                distance[node] = distance[src] + weight;
                pq.push({distance[node], node});
            }
        }
    }
    return distance;
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices and edges:\n";
    cin >> v >> e;
    vector<vector<int>> adj[v];
    cout << "Enter all the edges with weights:\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int source;
    cout << "Enter the source vertex :\n";
    cin >> source;
    vector<int> shortest_path = dijkstra(adj, v, source);
    for (int i = 0; i < v; i++)
        cout << i << " ";
    cout << "\n";
    for (int i = 0; i < v; i++)
        cout << shortest_path[i] << " ";
}