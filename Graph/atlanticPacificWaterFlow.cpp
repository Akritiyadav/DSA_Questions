#include <bits/stdc++.h>
using namespace std;

bool safe(int x, int y, int X, int Y) {
    return x >= 0 and y >= 0 and x < X and y < Y;
}

//DFA APPROACH

void dfs(int x, int y, vector<vector<int>>& mat, vector<vector<bool>>& vis) {
    vis[x][y] = true;
    int X[] = {-1, 1, 0, 0};
    int Y[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int x1 = x + X[i];
        int y1 = y + Y[i];
        if (safe(x1, y1, mat.size(), mat[0].size()) and vis[x1][y1] == false and
            mat[x1][y1] >= mat[x][y]) {
            dfs(x1, y1, mat, vis);
        }
    }
}

int dfsMain(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

    for (int i = 0; i < m; i++) {
        dfs(0, i, mat, pacific);
        dfs(n - 1, i, mat, atlantic);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 0, mat, pacific);
        dfs(i, m - 1, mat, atlantic);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += (pacific[i][j] and atlantic[i][j]);
        }
    }
    return ans;
}


// BFS APProach

void bfs(vector<vector<int>>& mat, queue<pair<int, int>>& q,
         vector<vector<bool>>& vis) {
    int n = mat.size();
    int m = mat[0].size();
    int X[] = {-1, 1, 0, 0};
    int Y[] = {0, 0, -1, 1};
    while (q.size()) {
        auto front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = front.first + X[i];
            int y = front.second + Y[i];
            if (safe(x, y, n, m) and
                mat[x][y] >= mat[front.first][front.second] and
                vis[x][y] == false) {
                vis[x][y] = true;
                q.push({x, y});
            }
        }
    }
}

int solve(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

    queue<pair<int, int>> q1, q2;

    for (int i = 0; i < m; i++) {
        pacific[0][i] = true;
        q1.push({0, i});
    }
    for (int i = 0; i < n; i++) {
        pacific[i][0] = true;
        q1.push({i, 0});
    }

    for (int i = 0; i < m; i++) {
        atlantic[n - 1][i] = true;
        q2.push({n - 1, i});
    }
    for (int i = 0; i < n; i++) {
        atlantic[i][m - 1] = true;
        q2.push({i, m - 1});
    }

    bfs(mat, q1, pacific);
    bfs(mat, q2, atlantic);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pacific[i][j] and atlantic[i][j]) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> mat =  { { 1, 2, 2, 3, 5 },
            { 3, 2, 3, 4, 4 },
            { 2, 4, 5, 3, 1 },
            { 6, 7, 1, 4, 5 },
            { 5, 1, 1, 2, 4 } };

    // cout << solve(mat);
    cout<<dfsMain(mat);
    return 0;
}