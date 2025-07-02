#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

// Manual sorting function (Bubble Sort)
void sortEdges(Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int find(int p[], int i) {
    while (p[i] != i) {
        i = p[i];
    }
    return i;
}

void kruskal(Edge edges[], int n, int e) {
    int p[100];
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    sortEdges(edges, e); // Use manual sort
    cout << "Edge\tWeight\n";
    for (int i = 0; i < e; i++) {
        int a = find(p, edges[i].u);
        int b = find(p, edges[i].v);
        if (a != b) {
            cout << edges[i].u << " - " << edges[i].v << "\t" << edges[i].w << "\n";
            p[a] = b;
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    Edge edges[100];
    cout << "Enter each edge as: u v weight\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    kruskal(edges, n, e);
    return 0;
}
