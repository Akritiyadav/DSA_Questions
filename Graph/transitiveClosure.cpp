#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int v, vector<vector<int>>& graph, vector<vector<int>>& ans) {
    ans[u][v] = 1;

    for (auto it : graph[v]) {
        if (ans[u][it] == 0) {
            dfs(u, it, graph, ans);
        }
    }
}

int main() {
    int V = 4;
    vector<vector<int>> graph(V);

    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(2);

    vector<vector<int>> ans(V, vector<int>(V, 0));
    for (int i = 0; i < V; i++) {
        dfs(i, i, graph, ans);
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}