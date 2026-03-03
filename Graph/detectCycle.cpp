#include <bits/stdc++.h>
using namespace std;

bool cycle(vector<vector<int>>& graph, int src, vector<bool>& visited) {
    int n = graph.size();
    if (visited[src]) return true;
    visited[src] = true;

    for (int i = 0; i < graph[src].size(); i++) {
        if (cycle(graph, graph[src][i], visited)) {
            return true;
        }
    }
    visited[src] = true;
    return false;
}

bool isCyclic(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (cycle(graph, i, visited)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> adj = {{1}, {2}, {0, 3}};

    cout << (isCyclic(adj) ? "true" : "false") << endl;
    return 0;
}