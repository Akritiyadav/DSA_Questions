#include <bits/stdc++.h>
using namespace std;

bool safe(int x, int y, int X, int Y) {
    return x >= 0 and y >= 0 and x < X and y < Y;
}

int solve(vector<vector<int>> mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2) {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int X[] = {-1, 1, 0, 0};
    int Y[] = {0, 0, -1, 1};

    while (q.size()) {
        auto front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = front.first + X[i];
            int y = front.second + Y[i];
            if (safe(x, y, n, m) and mat[x][y] == 1 and
                ans[x][y] > ans[front.first][front.second] + 1) {
                ans[x][y] = ans[front.first][front.second] + 1;
                q.push({x, y});
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != 0) {
                res = max(res, ans[i][j]);
            }
        }
    }
    return res;
}

int dfs(vector<vector<int>>& ans, vector<vector<int>>& graph, int x, int y,
        int val) {
    if (safe(x, y, graph.size(), graph[0].size()) && graph[x][y] == 1 &&
        ans[x][y] > val + 1) {
        ans[x][y] = val + 1;
        int X[] = {-1, 1, 0, 0};
        int Y[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int x1 = x + X[k];
            int y1 = y + Y[k];
            dfs(ans, graph, x1, y1, ans[x][y]);
        }
    }
}

int solvedfs(vector<vector<int>>& graph) {
    int n = graph.size(), m = graph[0].size();
    vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 2) {
                int X[] = {-1, 1, 0, 0};
                int Y[] = {0, 0, -1, 1};
                ans[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + X[k];
                    int y = j + Y[k];
                    dfs(ans, graph, x, y, 0);
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] != 0) {
                res = max(res, ans[i][j]);
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> mat = {
        {2, 1, 0, 2, 1}, {1, 0, 1, 2, 1}, {1, 0, 0, 2, 1}};
    auto ans = solvedfs(mat);
    cout << ans;
}