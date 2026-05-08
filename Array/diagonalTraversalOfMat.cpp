#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int>>& mat) {
    int n = mat.size();     // number of rows
    int m = mat[0].size();  // number of columns

    vector<int> res;  // to store final answer

    // =========================================================
    // 🔹 PART 1: Start from FIRST COLUMN (col = 0)
    // We take each row as a starting point
    // =========================================================
    for (int row = 0; row < n; row++) {
        int i = row;  // starting row
        int j = 0;    // always first column

        // Move in diagonal direction: UP-RIGHT ↗️
        // i-- (go up), j++ (go right)
        while (i >= 0 && j < m) {
            res.push_back(mat[i][j]);  // store current element

            i--;  // move one step up
            j++;  // move one step right
        }
    }

    // =========================================================
    // 🔹 PART 2: Start from LAST ROW (row = n-1)
    // We take each column (except 0 to avoid duplicate)
    // =========================================================
    for (int col = 1; col < m; col++) {
        int i = n - 1;  // always last row
        int j = col;    // starting column

        // Again move UP-RIGHT ↗️
        while (i >= 0 && j < m) {
            res.push_back(mat[i][j]);  // store element

            i--;  // move up
            j++;  // move right
        }
    }

    return res;  // final diagonal traversal
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16},
                               {17, 18, 19, 20}};
    vector<int> res = solve(mat);
    for (auto val : res) cout << val << " ";
    cout << endl;

    return 0;
}