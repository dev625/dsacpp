/* Approach : Start at some arbitrary node and
explore as far as possible along each branch
before backtracking.

So the Basic idea is to start from any node 
and mark the node and move to adjacent unmarked
node and continue this loop until there is no 
unmarked adjacent node.

Then backtrack and check for other
unmarked nodes and traverse them.
Finally Print the nodes in the path.*/

#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    //  A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V); // Graph Constructor
    void addEdge(int x, int y);
    void DFS();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int x, int y)
{
    adj[x].push_back(y); // Add y to x's list
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    /*Recur for all the vertices adjacent 
    to this vertex.*/
    for (auto i : adj[v])
    {
        if (visited[i] == false)
        {
            DFSUtil(i, visited);
        }
    }
}

/*DFS Traversal of the vertices reachable from 
v, this uses recursive DFSUtil.*/
void Graph::DFS()
{
    //Mark all the nodes as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    //For handling disconnected vertices,
    //we call the helper function on
    //all vertices from the start.
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSUtil(i, visited);
        }
    }
}

int main()
{
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 7);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.DFS();
}