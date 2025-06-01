#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for std::pair
#include <climits>

struct Edge {
    int dest;
    int weight;

    Edge(int d, int w) : dest(d), weight(w) {}
};

class Graph {
private:
    int V;
    std::vector<std::vector<Edge>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(Edge(dest, weight));
    }

    // TODO: Implement optimized Dijkstra’s algorithm using priority queue
    void dijkstra(int source) {
        // 1. Create a priority queue to store vertices and their distances
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> pq;

        // 2. Create vectors for tracking:
        std::vector<int> dist(V, INT_MAX);
        std::vector<int> parent(V, -1);
        std::vector<bool> visited(V, false);

        // 3. Initialize all distances as INFINITE and visited as false
        dist[source] = 0;
        pq.push({0, source});

        // 5. While the priority queue is not empty:
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            // Skip if already visited
            if (visited[u]) continue;

            visited[u] = true;

            // Explore all adjacent edges
            for (const Edge& edge : adjList[u]) {
                int v = edge.dest;
                int weight = edge.weight;

                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        // 6. Print the shortest paths
        printPaths(dist, parent);
    }

    // TODO: Implement function to print the shortest paths
    void printPaths(const std::vector<int>& dist, const std::vector<int>& parent) {
        std::cout << "Vertex\tDistance\tPath\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX) {
                std::cout << i << "\tINF\t\t-\n";
            } else {
                std::cout << i << "\t" << dist[i] << "\t\t";
                printPath(parent, i);
                std::cout << std::endl;
            }
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

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 2);

    int source = 0;
    std::cout << "Shortest paths from vertex " << source << " using optimized Dijkstra’s algorithm:\n";
    g.dijkstra(source);

    return 0;
}
