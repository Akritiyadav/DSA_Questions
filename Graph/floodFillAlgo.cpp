#include <bits/stdc++.h>
using namespace std;

bool safe(int x, int y, int n, int m) {
    return x >= 0 and y >= 0 and x < n and y < m;
}

vector<vector<int>> bfs(vector<vector<int>>& graph, int newColor, int sr,
                        int sc) {
    int n = graph.size(), m = graph[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int oldColor = graph[sr][sc];
    graph[sr][sc] = newColor;

    int X[] = {-1, 1, 0, 0};
    int Y[] = {0, 0, -1, 1};

    while (q.size()) {
        auto front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = front.first + X[i];
            int y = front.second + Y[i];
            if (safe(x, y, n, m) and graph[x][y] == oldColor) {
                graph[x][y] = newColor;
                q.push({x, y});
            }
        }
    }
    return graph;
}

void dfs(vector<vector<int>> &graph, int newColor, int oldColor, int sr,
         int sc) {
    int n = graph.size(), m = graph[0].size();
    graph[sr][sc] = newColor;

    int X[] = {-1, 1, 0, 0};
    int Y[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int x = sr + X[i];
        int y = sc + Y[i];
        if (safe(x, y, n, m) and graph[x][y] == oldColor) {
            dfs(graph, newColor, oldColor, x, y);
        }
    }
}

vector<vector<int>> dfsCaller(vector<vector<int>>&graph, int newColor, int sr,
                              int sc) {
    int n = graph.size(), m = graph[0].size();
    int oldColor = graph[sr][sc];
    dfs(graph, newColor, oldColor, sr, sc);
    return graph;
}

int main() {
    vector<vector<int>> img = {{1, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};

    int sr = 1, sc = 2;

    int newColor = 2;

    vector<vector<int>> result = dfsCaller(img, newColor, sr, sc);

    for (auto& row : result) {
        for (auto& pixel : row) {
            cout << pixel << " ";
        }

        cout << "\n ";
    }

    cout<<"-----------------------"<<endl;
     for (auto& row : img) {
        for (auto& pixel : row) {
            cout << pixel << " ";
        }

        cout << "\n ";
    }

    return 0;
}