#include <iostream>
#include <map>
#include <list>
using namespace std;
 
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    void addEdge(int x, int y);
    void dfs(int x);
};
 
void Graph::addEdge(int x, int y)
{
    adj[x].push_back(y); 
}
 
void Graph::dfs(int x)
{
    visited[x] = true;
    cout << x << " ";
    list<int>::iterator i;
    for (i = adj[x].begin(); i != adj[x].end(); i++) {
        if (!visited[*i]) dfs(*i);
    }
        
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    
    graph.dfs(2);
    return 0;
}