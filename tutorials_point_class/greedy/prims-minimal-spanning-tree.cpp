#include <iostream>
#include <iomanip>
#include <climits> // For INT_MAX

using namespace std;

const int V = 6;

// Function to find vertex with minimum key value not in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Print MST using parent[]
void printMST(int parent[], int graph[V][V], const string labels[]) {
    cout << "Edge   Weight\n";
    for (int i = 1; i < V; i++) {
        cout << labels[parent[i]] << " - " << labels[i] << "    " << graph[i][parent[i]] << "\n";
    }
}

// Prim's algorithm
void primMST(int graph[V][V], const string labels[]) {
    int parent[V]; // To store MST
    int key[V]; // To pick min weight edge
    bool mstSet[V]; // To track vertices in MST

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0; // Start from vertex 0
    parent[0] = -1; // First node is root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, labels);
}

int main() {
    int graph[V][V] = {
        // S   A  B  C  D  E
        {0, 12, 8, 0, 0, 0}, //   S
        {12, 0, 9, 22, 0, 11}, // A
        {8, 9, 0, 0, 0, 14}, //   B
        {0, 22, 0, 0, 15, 18}, // C
        {0, 0, 0, 15, 0, 3}, //   D
        {0, 11, 14, 18, 3, 0} //  E
    };

    const string labels[V] = {"S", "A", "B", "C", "D", "E"};

    cout << "Prim's Minimum Spanning Tree:\n";
    primMST(graph, labels);

    return 0;
}
