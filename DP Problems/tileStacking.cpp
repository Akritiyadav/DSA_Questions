#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k) {
    int dp[n + 1][m + 1];
    fill_n(&dp[0][0], (n + 1) * (m + 1), 0);

    // Base case:
    // Height 0 can always be formed in 1 way (choose nothing)
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 1;
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {      // height
        for (int j = 1; j <= m; j++) {  // tile size

            // Case 1: don't use tile size j
            dp[i][j] = dp[i][j - 1];

            // Case 2: use tile size j (1 to k times)
            for (int t = 1; t <= min(i, k); t++) {
                dp[i][j] += dp[i - t][j - 1];
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n = 3, m = 3, k = 2;
    cout << solve(n, m, k);
}