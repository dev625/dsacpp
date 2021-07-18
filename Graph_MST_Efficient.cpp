#include <bits/stdc++.h>
using namespace std;

void MST(vector<vector<int>> adj[], int v)
{
    vector<int> parent(v, -1), key(v, INT_MAX);
    vector<int> mst(v, false);
    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //pq will hold {keyvalue,node}
    pq.push({0, 0});
    while (pq.empty() == false)
    {
        int minkey = pq.top().second;
        pq.pop();
        mst[minkey] = true;
        for (auto &x : adj[minkey])
        {
            int node = x[0];
            int weight = x[1];
            if (mst[node] == false && weight < key[node])
            {
                parent[node] = minkey;
                key[node] = weight;
                pq.push({key[node], node});
            }
        }
    }
    for (auto &x : parent)
        cout << x << " ";
    cout << "\n";
    for (auto &x : key)
        cout << x << " ";
    cout << "\n";
    for (auto &x : mst)
        cout << x << " ";
    cout << "\b";
}

int main()
{
    int v, e, x, y, weight;
    cin >> v >> e;
    vector<vector<int>> adj[v];
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> weight;
        adj[x].push_back({y, weight});
        adj[y].push_back({x, weight});
    }
    MST(adj, v);
}