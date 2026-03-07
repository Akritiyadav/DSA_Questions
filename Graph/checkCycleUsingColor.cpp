#include <bits/stdc++.h>
using namespace std;

const int white = 0, gray = 1, black = 2;

using vvi = vector<vector<int>>;

vvi constructadj(int V, const vvi& edges) {
    vvi adj(V);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    return adj;
}

bool dfs(vvi& graph, vector<int>& visited, int src) {
    visited[src] = gray;

    for (int i = 0; i < graph[src].size(); i++) {
        if (visited[graph[src][i]] == gray)
            return true;
        else if (visited[graph[src][i]] == white &&
                 dfs(graph, visited, graph[src][i])) {
            return true;
        }
    }
    visited[src] = black;
    return false;
}

bool isCyclic(vvi& edges, int V) {
    vvi graph = constructadj(V, edges);
    vector<int> visited(V, white);
    for (int i = 0; i < V; i++) {
        if (visited[i] == white and dfs(graph, visited, i)) {
            return true;
        }
    }
    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2},
                                 {2, 0}, {2, 3}, {3, 3}};

    cout << (isCyclic(edges, V) ? "true" : "false") << endl;

    return 0;
}
