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
        adjList[dest].push_back(Edge(src, weight)); // For undirected graph
    }

    // TODO : Implement optimized Prim ’s algorithm using priority queue
    void primMST() {
        // 1. Create a priority queue to store vertices and their key values
        // Use std :: pair <int , int > where first is the weight and second is the vertex

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

        // 2. Create vectors for tracking the MST :
        // - key []: Key values used to pick minimum weight edge
        // - parent []: Array to store the MST
        // - inMST []: To represent vertices included in MST

        std::vector<int> key(V, INT_MAX);
        std::vector<int> parent(V, -1);
        std::vector<bool> inMST(V, false);

        // 3. Initialize key values as INFINITE and inMST as false
        key[0] = 0;

        // 4. Insert the first vertex into the priority queue with key value 0
        pq.push({0, 0});

        // 5. While the priority queue is not empty :
        // a. Extract the minimum key vertex from the priority queue
        // b. Include the extracted vertex in the MST
        // c. For all adjacent vertices , update key values and insert into the queue if needed
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (const auto& edge : adjList[u]) {
                int v = edge.dest;
                int weight = edge.weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        // 6. Print the MST
        printMST(parent);
    }

    // TODO : Implement function to print the MST
    void printMST(const std::vector<int>& parent) {
        std::cout << "Edge\tWeight\n";
        int totalWeight = 0;

        // Print each edge and its weight in the MST
        for (int i = 1; i < V; ++i) {
            for (const auto& edge : adjList[i]) {
                if (edge.dest == parent[i]) {
                    std::cout << parent[i] << " - " << i << "\t" << edge.weight << "\n";
                    totalWeight += edge.weight;
                    break;
                }
            }
        }

        std::cout << "Total MST weight: " << totalWeight << std::endl;
    }
};

int main() {
    Graph g(9); // Create a graph with 9 vertices (0 to 8)

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    std::cout << "Minimum Spanning Tree using optimized Prim's algorithm:\n";
    g.primMST();

    return 0;
}
