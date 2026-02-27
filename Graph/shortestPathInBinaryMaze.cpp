#include <bits/stdc++.h>
using namespace std;

bool safe(int x, int y, int X, int Y) {
    return x >= 0 and y >= 0 and x < X and y < Y;
}

int bfs(vector<vector<int>>& mat, vector<int>& src, vector<int>& dest) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int srcx = src[0], srcy = src[1];
    int destx = dest[0], desty = dest[1];

    if (mat[srcx][srcy] == 0 || mat[destx][desty] == 0) return -1;

    queue<pair<pair<int, int>, int>> q;

    q.push({{srcx, srcy}, 0});
    vis[srcx][srcy] = true;

    int X[] = {-1, 1, 0, 0};
    int Y[] = {0, 0, -1, 1};

    while (q.size()) {
        auto front = q.front();
        q.pop();

        if (front.first.first == destx and front.first.second == desty)
            return front.second;

        for (int i = 0; i < 4; i++) {
            int x = front.first.first + X[i];
            int y = front.first.second + Y[i];
            if (safe(x, y, n, m) and mat[x][y] == 1 and vis[x][y] == false) {
                vis[x][y] = true;
                q.push({{x, y}, front.second + 1});
            }
        }
    }
    return -1;
}


int main(){
     vector<vector<int>> mat =
    {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
                  vector<int>src={0,0};
                  vector<int>dest={3,4};
                  cout<<bfs(mat,src,dest);
}