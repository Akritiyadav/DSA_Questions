#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<vector<int>> graph) {
    int v = graph.size();
    vector<int> st(v, false);  // O(n)
    queue<int> q;

    q.push(src);

    while (q.size()) {
        int front = q.front();
        q.pop();

        if (st[front] == false) {
            cout << front << " ";
            st[front] = true;
        } else {
            continue;
        }
        for (auto child : graph[front]) {
            q.push(child);
        }
    }
}

// bfs using set it will take o(logn) search

void bfs1(int src, vector<vector<int>> graph) {
    int v = graph.size();
    set<int> st;
    queue<int> q;

    q.push(src);

    while (q.size()) {
        int front = q.front();
        q.pop();

        if (!st.count(front)) {
            cout << front << " ";
            st.insert(front);
        } else {
            continue;
        }
        for (auto child : graph[front]) {
            q.push(child);
        }
    }
}

vector<int> bfs2(vector<vector<int>>& graph) {
    int v = graph.size();
    int src = 0;
    queue<int> q;
    vector<int> res;
    vector<bool> visited(v,false);
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int front = q.front();
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
    vector<int> res = bfs2(graph);
    for (int i : res) {
        cout << i << " ";
    }
}