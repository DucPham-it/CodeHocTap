#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    // TODO: Implement BFS traversal starting from source vertex
    void BFS(int source) {
        if (source < 0 || source >= V) {
            return;
        }

        std::vector<bool> visited(V, false);
        std::queue<int> q;
        visited[source] = true;
        q.push(source);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            std::cout << current << " ";

            for (int i : adjList[current]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }           
    }

    // TODO: Implement function to find shortest paths from source to all vertices
    void shortestPath(int source) {
        if (source < 0 || source >= V) {
            return;
        }

        std::vector<bool> visited(V, false);
        std::vector<int> distance(V, -1);
        std::vector<int> parent(V, -1);
        std::queue<int> q;
        visited[source] = true;
        distance[source] = 0;
        q.push(source);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int w : adjList[current]) {
                if (!visited[w]) {
                    visited[w] = true;
                    distance[w] = distance[current] + 1;
                    parent[w] = current;
                    q.push(w);
                }
            }
        }

        for (int i = 0; i < V; i++) {
            std::cout << "Vertex " << i << ": distance = " << distance[i] << ", path = ";
            printPath(parent, i);
            std::cout << std::endl;
        }
    }

    // Helper function to print path from source to destination
    void printPath(const std::vector<int>& parent, int dest) {
        if (parent[dest] == -1) {
            std::cout << dest;
            return;
        }
        printPath(parent, parent[dest]);
        std::cout << " -> " << dest;
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices (0 to 5)

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    std::cout << "BFS traversal starting from vertex 0:" << std::endl;
    g.BFS(0);

    std::cout << "\nShortest paths from vertex 0:" << std::endl;
    g.shortestPath(0);

    return 0;
}
