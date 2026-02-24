#include <bits/stdc++.h>
using namespace std;

int recur(int m, int n, int x) {
    if (n == 0 and x == 0) return 1;

    if (n == 0 or x < 0) return 0;

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += recur(m, n - 1, x - i);
    }
    return ans;
}

int solve(int m, int n, int x, vector<vector<int>>& dp) {
    if (n == 0 and x == 0) return 1;

    if (n == 0 or x < 0) return 0;

    if (dp[n][x] != -1) return dp[n][x];

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += solve(m, n - 1, x - i, dp);
    }

    return dp[n][x] = ans;
}

int solveDP(int m, int n, int x) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= m && j - k >= 0; k++) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    return dp[n][x];
}

int main() {
    int m = 6, n = 3, x = 12;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    // cout << solve(m, n, x, dp);
    cout << solveDP(m, n, x);
}