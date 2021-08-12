/*Program to print BFS Traversal of an Undirected
graph from some source vertex s*/
#include "bits/stdc++.h"
using namespace std;
class Graph
{
    int v;          // Number of Vertices in the Graph
    list<int> *adj; // Pointer to an array of lists
public:
    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
    }
    void addEdge(int x, int y); //Function to add an edge to the graph
    void BFS(int s);            //BFS Traversal of the Graph
};

void Graph::addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void Graph::BFS(int s)
{
    //  Initially marking all the vertices as not visited
    vector<bool> visited(v, false);
    //  Creating a queue for Breadth First Search
    list<int> queue;
    // We mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
    // Iterator i will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
    while (!queue.empty())
    {
        //Dequeue a node from the node and print it
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
    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.BFS(1);
}