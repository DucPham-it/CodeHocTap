#include <iostream>
#include <vector>

struct Edge {
    int dest;
    int weight;

    Edge(int d, int w = 1) : dest(d), weight(w) {}
};

class Graph {
private:
    int V; // Number of vertices
    std::vector<std::vector<Edge>> adjList;

public:
    // TODO: Implement constructor to initialize the graph with V vertices
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // TODO: Implement function to add an edge from src to dest with weight
    void addEdge(int src, int dest, int weight = 1) {
        adjList[src].push_back(Edge(dest, weight));
    }

    // TODO: Implement function to check if there is an edge from src to dest
    bool isEdge(int src, int dest) {
        for (Edge e : adjList[src]) {
            if (e.dest == dest) {
                return true;
            }
        }
        return false; // Replace with your implementation
    }

    // TODO: Implement function to get the weight of an edge from src to dest
    int getWeight(int src, int dest) {
        for (Edge e : adjList[src]) {
            if (e.dest == dest) {
                return e.weight;
            }
        }
        return 0; // Replace with your implementation
    }

    // TODO: Implement function to print the adjacency list
    void printGraph() {
        for (int i = 0; i < V; i++) {
            std::cout << i << " -> ";
            for (Edge e : adjList[i]) {
                std::cout << "(" << e.dest << ", " << e.weight << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices (0 to 4)

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 5);
    g.addEdge(4, 0, 6);

    std::cout << "Adjacency List representation of the graph:" << std::endl;
    g.printGraph();

    // Test isEdge and getWeight
    std::cout << "\nTesting edges:\n";
    std::cout << "Is there an edge from 0 to 1? " << (g.isEdge(0, 1) ? "Yes" : "No") << std::endl;
    std::cout << "Is there an edge from 1 to 0? " << (g.isEdge(1, 0) ? "Yes" : "No") << std::endl;
    std::cout << "Weight of edge from 2 to 3: " << g.getWeight(2, 3) << std::endl;

    return 0;
}
