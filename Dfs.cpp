#include <iostream>
#include <stack>
using namespace std;

const int MAX_NODES = 100;

void dfs(int start, int graph[MAX_NODES][MAX_NODES], bool visited[], int nodes) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << (node + 1) << " ";  // Convert back to 1-based for display

        for (int i = 0; i < nodes; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int nodes, edges;
    int graph[MAX_NODES][MAX_NODES] = {0};
    bool visited[MAX_NODES] = {false};

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (format: u v for edge between u and v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;  // Convert to 0-based indexing
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int startNode;
    cout << "Enter starting node for DFS: ";
    cin >> startNode;
    startNode--;  // Convert to 0-based indexing

    dfs(startNode, graph, visited, nodes);

    return 0;
}