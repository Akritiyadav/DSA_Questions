#include <bits/stdc++.h>
using namespace std;

bool safe(int x, int y, int X, int Y) {
    return x >= 0 and y >= 0 and x < X and y < Y;
}

// DFS approach
void dfs(vector<vector<char>>& graph, int x, int y) {
    int n = graph.size(), m = graph[0].size();
    if (!safe(x, y, n, m)) return;

    if (graph[x][y] != 'L') return;
    graph[x][y] = 'Q';

    int X[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int Y[] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int k = 0; k < 8; k++) {
        int x1 = x + X[k];
        int y1 = y + Y[k];
        dfs(graph, x1, y1);
    }
}
int solve(vector<vector<char>>& graph) {
    int n = graph.size(), m = graph[0].size();
    int ans = 0;
    int X[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int Y[] = {0, 0, -1, 1, -1, 1, -1, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'L') {
                ans++;
                graph[i][j] = 'Q';
                for (int k = 0; k < 8; k++) {
                    int x = i + X[k];
                    int y = j + Y[k];
                    dfs(graph, x, y);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'Q') {
                graph[i][j] = 'L';
            }
        }
    }
    return ans;
}

// BFS Approach
void bfs(vector<vector<char>>& graph, int x, int y) {
    int n = graph.size(), m = graph[0].size();
    int X[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int Y[] = {0, 0, -1, 1, -1, 1, -1, 1};
    queue<pair<int, int>> q;
    q.push({x, y});
    graph[x][y] = 'Q';

    while (q.size()) {
        auto front = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x1 = front.first + X[i];
            int y1 = front.second + Y[i];
            if (safe(x1, y1, n, m) and graph[x1][y1] == 'L') {
                graph[x1][y1] = 'Q';
                q.push({x1, y1});
            }
        }
    }
}

int solveBfs(vector<vector<char>>& graph) {
    int n = graph.size(), m = graph[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'L') {
                ans++;
                bfs(graph, i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'Q') {
                graph[i][j] = 'L';
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<char>> grid = {{'L', 'W', 'W', 'W', 'W'},
                                 {'W', 'L', 'W', 'W', 'L'},
                                 {'L', 'W', 'W', 'L', 'L'},
                                 {'W', 'W', 'W', 'W', 'W'},
                                 {'L', 'W', 'L', 'L', 'W'}};

    // printing the number of islands
    cout << solveBfs(grid) << endl;
}