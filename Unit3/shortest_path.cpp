#include <iostream>
using namespace std;

#define MAX_VERTICES 10  // Defines the maximum number of vertices allowed in the graph
#define INF 99999        // INF used to initialize distance (limit)

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int start, int numVertices) {
    int distance[MAX_VERTICES];         // Stores the shortest distance to each vertex
    bool visited[MAX_VERTICES] = {false}; // Keeps track of visited vertices

    // Initialize all distances as infinity and visited vertices as false
    for (int i = 0; i < numVertices; i++) {
        distance[i] = INF;
    }
    distance[start] = 0; // Distance to the starting vertex is 0

    // Dijkstra's Algorithm
    for (int count = 0; count < numVertices - 1; count++) {
        int minDist = INF;
        int minIndex;

        // Find the vertex with the minimum distance that hasn't been visited
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && distance[v] < minDist) {
                minDist = distance[v];
                minIndex = v;
            }
        }

        visited[minIndex] = true; // Mark the selected vertex as visited

        // Update distances of the adjacent vertices of the selected vertex
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[minIndex][v] && distance[minIndex] != INF) {
                int newDist = distance[minIndex] + graph[minIndex][v];
                if (newDist < distance[v]) {
                    distance[v] = newDist;
                }
            }
        }
    }

    // Print the distances to all vertices
    for (int i = 0; i < numVertices; i++) {
        if (distance[i] == INF) {
            cout << "Distance from " << start << " to " << i << " is infinity" << endl;
        } else {
            cout << "Distance from " << start << " to " << i << " is " << distance[i] << endl;
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix
    int numVertices;

    cout << "Enter the number of vertices (max " << MAX_VERTICES << "): ";
    cin >> numVertices;

    cout << "Enter the adjacency matrix (use 0 for no edge):" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter the starting vertex (0 to " << numVertices - 1 << "): ";
    cin >> start;

    dijkstra(graph, start, numVertices);

    return 0;
}
