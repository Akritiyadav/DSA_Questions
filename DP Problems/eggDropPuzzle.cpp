#include <bits/stdc++.h>
using namespace std;

/**
 * Worst attempts = max(break case, not-break case)
 */
int recur(int n, int k) {
    if (k == 1 or k == 0) return k;
    if (n == 1) return k;

    int res = INT_MAX;
    for (int i = 1; i <= k; i++) {
        int ans = 1 + max(recur(n - 1, i - 1), recur(n, k - i));
        if (ans < res) {
            res = ans;
        }
    }
    return res;
}

int solve(int n, int k, vector<vector<int>>& dp) {
    if (k == 1 or k == 0) return k;
    if (n == 1) return k;

    if (dp[n][k] != -1) return dp[n][k];

    int res = INT_MAX;
    for (int i = 1; i <= k; i++) {
        int ans = 1 + max(solve(n - 1, i - 1, dp), solve(n, k - i, dp));
        if (ans < res) {
            res = ans;
        }
    }
    dp[n][k] = res;
    return res;
}

int solveDP(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base case: 1 egg
    for (int i = 1; i <= k; i++) {
        dp[1][i] = i;
    }

    // Base case: 0 or 1 floor
    for (int e = 1; e <= n; e++) {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = INT_MAX;

            for (int t = 1; t <= j; t++) {
                int ans = 1 + max(dp[i - 1][t - 1], dp[i][j - t]);
                dp[i][j] = min(dp[i][j], ans);
            }
        }
    }
    return dp[n][k];
}

int main() {
    int n = 2, k = 10;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    // cout << recur(n, k);
    cout << solveDP(n, k);
}