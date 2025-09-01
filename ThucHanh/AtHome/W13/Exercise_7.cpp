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
        adjMatrix[dest][src] = weight; // For undirected graph
    }

    // TODO: Implement Prim’s algorithm to find MST
    void primMST() {
        std::vector<int> key(V, INT_MAX);     // Key values used to pick minimum weight edge
        std::vector<int> parent(V, -1);       // Array to store the MST
        std::vector<bool> mstSet(V, false);   // To represent vertices included in MST

        key[0] = 0; 

        for (int i = 0; i < V - 1; i++) {
            int u = minKey(key, mstSet); // a. Pick the vertex with minimum key value that is not yet included
            mstSet[u] = true; // b. Include the picked vertex in the MST

            // c. Update key and parent values of adjacent vertices
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        // 5. Print the MST
        printMST(parent);
    }

    // TODO : Implement function to find the vertex with minimum key value
    int minKey(const std::vector<int>& key, const std::vector<bool>& mstSet) {
        int min = INT_MAX, min_index = -1;

        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }

        return min_index;
    }

    // TODO : Implement function to print the MST
    void printMST(const std::vector<int>& parent) {
        std::cout << "Edge\tWeight\n";
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            std::cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << "\n";
            totalWeight += adjMatrix[i][parent[i]];
        }
        std::cout << "Total MST weight: " << totalWeight << std::endl;
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices (0 to 4)

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    std::cout << "Minimum Spanning Tree using Prim's algorithm:" << std::endl;
    g.primMST();

    return 0;
}
