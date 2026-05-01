#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size();
    int m = mat[0].size();

    // Start from top-right corner
    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0) {

        if (mat[row][col] == x) {
            return true;  // found
        }

        else if (x < mat[row][col]) {
            col--;  // move left (smaller values)
        }

        else {
            row++;  // move down (larger values)
        }
    }

    return false; // not found
}

int main() {
    vector<vector<int>> mat = {
        {3, 30, 38},
        {20, 52, 54},
        {35, 60, 69}
    };

    int x = 35;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}