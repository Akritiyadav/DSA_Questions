#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int>>& graph) {
    int v = graph.size();
    int src = 0;
    queue<int> q;
    q.push(src);
    vector<bool> visited(v, false);
    vector<int> res;
    visited[src] = true;
    while (q.size()) {
        auto front = q.front();
        q.pop();
        res.push_back(front);
        for (auto it : graph[front]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }
    return res;
}

int main() {
     vector<vector<int>> graph(5);

    graph[0] = {1, 2};
    graph[1] = {0, 2};
    graph[2] = {0, 1, 3, 4};
    graph[3] = {2};
    graph[4] = {2};
     
    // bfs1(0,graph);
    vector<int> res = solve(graph);
    for (int i : res) {
        cout << i << " ";
    }
}
