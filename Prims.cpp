#include <iostream>
using namespace std;

#define INF 9999

void prims(int graph[10][10], int V) {
    int selected[10] = {0};
    selected[0] = 1;

    cout << "Edge\tWeight\n";

    for (int edge = 0; edge < V - 1; edge++) {
        int min = INF, x = 0, y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        cout << x << " - " << y << "\t" << graph[x][y] << "\n";
        selected[y] = 1;
    }
}

int main() {
    int V, graph[10][10];
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix (use 0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    prims(graph, V);
    return 0;
}
