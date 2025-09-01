#include <iostream>
#include <vector>
#include <climits>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices) : V(vertices) {
        adjMatrix.resize(V, std::vector<int>(V, 0));
    }

    void addEdge(int src, int dest, int weight) {
        adjMatrix[src][dest] = weight;
    }

    // TODO: Implement Dijkstra’s algorithm
    void dijkstra(int source) {
        // 1. Create arrays to store the shortest distance and whether a vertex is finalized
        // - dist[]: Shortest distance from source to i
        // - sptSet[]: True if vertex i is included in shortest path tree
        std::vector<int> dist(V, INT_MAX);
        std::vector<bool> sptSet(V, false);

        // 2. Initialize all distances as INFINITE and sptSet as false
        // (already done above)

        // 3. Set distance of source vertex as 0
        dist[source] = 0;

        // 4. Find shortest path for all vertices:
        for (int count = 0; count < V - 1; ++count) {
            // a. Pick the vertex with minimum distance that is not yet processed
            int u = minDistance(dist, sptSet);

            // b. If no reachable vertex left
            if (u == -1)
                break;

            // c. Mark the picked vertex as processed
            sptSet[u] = true;

            // d. Update dist[] values of adjacent vertices
            for (int v = 0; v < V; ++v) {
                if (!sptSet[v] && adjMatrix[u][v] > 0 && dist[u] != INT_MAX &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        // 5. Print the shortest distances
        printSolution(dist);
    }

    // TODO: Implement function to find the vertex with the minimum distance
    int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet) {
        int min = INT_MAX, min_index = -1;

        // Find the vertex with the minimum distance value
        for (int v = 0; v < V; ++v) {
            if (!sptSet[v] && dist[v] < min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    // TODO: Implement function to print the shortest distances
    void printSolution(const std::vector<int>& dist) {
        std::cout << "Vertex\tDistance from Source\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX)
                std::cout << i << "\tINF\n";
            else
                std::cout << i << "\t" << dist[i] << "\n";
        }
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
    g.addEdge(3, 4, -1); 
    g.addEdge(4, 5, -2);

    int source = 0;
    std::cout << "Shortest paths from vertex " << source << " using Dijkstra’s algorithm:\n";
    g.dijkstra(source);

    return 0;
}
