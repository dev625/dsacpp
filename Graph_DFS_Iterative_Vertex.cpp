/*This function only prints the vertices reachable from an
arbitrary vertex and does not perform DFS of the whole graph*/
#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int x, int y);
    void DFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int x, int y)
{
    adj[x].push_back(y);
}

void Graph::DFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    stack<int> S;
    S.push(s);
    list<int>::iterator i;
    while (S.empty() == false)
    {
        int top = S.top();
        S.pop();
        if (!visited[top])
        {
            cout << top << " ";
            visited[top] = true;
        }

        for (i = adj[top].begin(); i != adj[top].end(); i++)
        {
            if (!visited[*i])
                S.push(*i);
        }
    }
}
int main()
{
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(5, 4);
    g.addEdge(6, 7);
    g.DFS(3);
}