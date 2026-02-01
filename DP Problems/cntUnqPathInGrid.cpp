#include <bits/stdc++.h>
using namespace std;

int countPath(int m, int n, int i, int j) {
    if (i < 0 or j < 0) return 0;
    if (i == 0 && j == 0) return 1;
    int left = 0, up = 0;
    left = countPath(m, n, i, j - 1);
    up = countPath(m, n, i - 1, j);
    return left + up;
}

int countDP(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int j = 1; j <n; j++) {
        dp[0][j] = dp[0][j-1];
    }
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0];
    }
    for (int i = 1; i <m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    return dp[m-1][n-1];
}
int main() {
    int m = 3, n = 3;
    cout << countDP(m, n);
}
