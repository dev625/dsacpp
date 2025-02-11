/*Program to print BFS Traversal
from a given source vertex. BFS(int s) traverses
vertices reachable from vertex s*/

#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V; // Number of vertices

    //Pointer to an array containing adjacency lists
    list<int> *adj;

public:
    Graph(int V); //Constructor

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // Prints BFS Traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); //Add w to v's list
}

void Graph::BFS(int s)
{
    // Initially mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices
    // of a vertex
    list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(7);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 3);

    g.BFS(1);
    cout << "\n";
    g.BFS(4);
}