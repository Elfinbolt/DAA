#include <iostream>
#include <stack>
using namespace std;

const int MAX_NODES = 100;

// Utility to convert char/node string to index
int nodeToIndex(string node) {
    if (isdigit(node[0]))  // Numeric node
        return stoi(node) - 1; // 1-based to 0-based
    else                   // Alphabetic node
        return toupper(node[0]) - 'A';
}

// Utility to convert index to node label
string indexToNode(int index, bool useAlphabet) {
    if (useAlphabet)
        return string(1, 'A' + index);
    else
        return to_string(index + 1);
}

void dfs(int start, int graph[MAX_NODES][MAX_NODES], bool visited[], int nodes, bool useAlphabet) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << indexToNode(node, useAlphabet) << " ";

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
    bool useAlphabet = false;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Use alphabets for nodes? (1 for Yes, 0 for No): ";
    cin >> useAlphabet;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (e.g., A B or 1 2):\n";
    for (int i = 0; i < edges; i++) {
        string u_str, v_str;
        cin >> u_str >> v_str;
        int u = nodeToIndex(u_str);
        int v = nodeToIndex(v_str);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    string startStr;
    cout << "Enter starting node for DFS: ";
    cin >> startStr;
    int startNode = nodeToIndex(startStr);

    dfs(startNode, graph, visited, nodes, useAlphabet);

    return 0;
}
