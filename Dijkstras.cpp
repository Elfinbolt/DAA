#include <iostream>
using namespace std;

const int INF = 9999;
const int MAX = 100; // Max allowed vertices

// Function to find the vertex with minimum distance
int min_dist(int dist[], bool visited[], int V) {
    int minimum = INF, ind = -1;
    for (int k = 0; k < V; k++) {
        if (!visited[k] && dist[k] <= minimum) {
            minimum = dist[k];
            ind = k;
        }
    }
    return ind;
}

void greedy_dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = min_dist(dist, visited, V);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << char(65 + i) << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int V;
    int graph[MAX][MAX];

    cout << "Enter the number of vertices (max " << MAX << "): ";
    cin >> V;

    cout << "Enter the adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cout << "Enter the source vertex index (0 to " << V - 1 << "): ";
    cin >> source;

    greedy_dijkstra(graph, source, V);

    return 0;
}
