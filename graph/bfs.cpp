#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> l;
    public:
        void addEdge(int x, int y) {
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void bfs(T src) {
            map<T, int> visited;
            queue<T> q;
            q.push(src);
            visited[src] = true;
            while(!q.empty()) {
                T node = q.front();
                q.pop();
                cout << node << " ";
                for(int i : l[node]) {
                    if(!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Graph<int> graph;
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
    graph.addEdge(4,5);

    graph.bfs(0);
    return 0;
}