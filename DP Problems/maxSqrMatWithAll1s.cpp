#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == 1) {
                mat[i][j] =
                    1 + min({mat[i - 1][j], mat[i][j - 1], mat[i - 1][j - 1]});
            }
        }
    }
    int res = 0;
    for (vector<int> ans : mat) {
        for (int i : ans) {
            res = max(res, i);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> mat = {{0, 1, 1, 0, 1}, {1, 1, 0, 1, 0},
                               {0, 1, 1, 1, 0}, {1, 1, 1, 1, 0},
                               {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}};
    cout << solve(mat) << endl;

    return 0;
}