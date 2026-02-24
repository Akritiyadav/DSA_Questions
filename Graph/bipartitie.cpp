#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;

bool solveBfs(vvi& graph) {
    int n = graph.size();
    vector<int> ans(n, -1);
    ans[0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 1});
    while (q.size()) {
        auto front = q.front();
        q.pop();
        for (int i = 0; i < graph[front.first].size(); i++) {
            int v = graph[front.first][i];
            if (ans[v] == front.second) {
                return false;
            } else if (ans[v] == -1) {
                ans[v] = 1 - front.second;
                q.push({v, ans[v]});
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> edges = {{0, 1},{0,2},{1, 2}, {2, 3}};
    int cntVertices = 0;
    for (vector<int> edge : edges) {
        cntVertices = max({cntVertices, edge[0], edge[1]});
    }

    vector<vector<int>> graph(cntVertices+1, vector<int>());
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    if (solveBfs(graph))
        cout << "true";
    else
        cout << "false";

    return 0;
}