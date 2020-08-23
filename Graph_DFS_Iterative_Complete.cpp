#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    void DFS_Iterative_Util(int s, bool visited[]);

public:
    Graph(int v);
    void addEdge(int x, int y);
    void DFS();
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int x, int y)
{
    adj[x].push_back(y);
}

void Graph::DFS_Iterative_Util(int s, bool visited[])
{
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

void Graph::DFS()
{
    bool *visited = new bool[v];
    int i;
    for (i = 0; i < v; i++)
        visited[i] = false;
    for (i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFS_Iterative_Util(i, visited);
        }
    }
}

int main()
{
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(5, 4);
    g.addEdge(6, 7);
    g.addEdge(8, 0);
    g.DFS();
}