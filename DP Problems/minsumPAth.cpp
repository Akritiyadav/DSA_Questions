#include <bits/stdc++.h>
using namespace std;

/**
 *   [[2,0,0,0],
    [3, 7,0,0],
    [8, 5, 6,0],
    [6, 1, 9, 3]]
 */
int solve(int i, int j, vector<vector<int>>& arr) {
    if (i == 0 && j == 0) {
        return arr[0][0];
    }
    int up = solve(i - 1, j, arr);
    int upLeft = solve(i - 1, j - 1, arr);
    return arr[i][j] + min(up, upLeft);
}
int minPathSum(vector<vector<int>>& arr) {
    int n = arr.size() - 1;
    int ans = INT_MIN;
    for (int j = 0; j < arr[n].size(); j++) {
        ans = min(ans, solve(n, j, arr));
    }
    return ans;
}

int minPathSumDP(vector<vector<int>> arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (j == 0) {
                arr[i][j] += arr[i - 1][j];
                continue;
            }
            if (j == arr[i].size() - 1) {
                arr[i][j] += arr[i - 1][j - 1];
                continue;
            }
            arr[i][j] += min(arr[i - 1][j], arr[i - 1][j - 1]);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < arr[n - 1].size(); i++) {
        ans = min(ans, arr[n - 1][i]);
    }
    return ans;
}
int main() {
    vector<vector<int>> triangle{{2}, {3, 9}, {1, 6, 7}};
    cout << minPathSum(triangle);
    return 0;
}