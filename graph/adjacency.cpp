#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l;
    public:
        Graph(int V) {
            this->V = V;
            l = new list<int>[V];
        }
        void addEdge(int x, int y) {
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void printAdjacencyList() {
            for(int i = 0; i < V; i++) {
                cout << "Vertex: " << i << "-->";
                for(int j : l[i]) {
                    cout << j << " ";
                }
                cout << "\n";
            }
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(1,2);
    cout << "---------Adjacency List-----------\n";
    graph.printAdjacencyList();

    return 0;
}