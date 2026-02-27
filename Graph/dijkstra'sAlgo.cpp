#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int src) {
    int n = graph.size();
    vector<int> ans(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    ans[src] = 0;
    pq.push({0, src});

    while (pq.size()) {
        auto top = pq.top();
        pq.pop();

        for (int i = 0; i < graph[top.second].size(); i++) {
            auto v = graph[top.second][i];
            if (ans[v.first] > ans[top.second] + v.second) {
                ans[v.first] = ans[top.second] + v.second;
                pq.push({ans[v.first], v.first});
            }
        }
    }
    return ans;
}

int main() {
    int src = 0;

    vector<vector<pair<int, int>>> adj(5);
    adj[0] = {{1, 4}, {2, 8}};
    adj[1] = {{0, 4}, {4, 6}, {2, 3}};
    adj[2] = {{0, 8}, {3, 2}, {1, 3}};
    adj[3] = {{2, 2}, {4, 10}};
    adj[4] = {{1, 6}, {3, 10}};

    vector<int> result = dijkstra(adj, src);

    for (int d : result) cout << d << " ";
    return 0;
}
