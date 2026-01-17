#include <bits/stdc++.h>
using namespace std;

int minCostPathDP(vector<vector<int>>& cost) {
    int n = cost.size();
    int m = cost[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = cost[0][0];
    // for (int i = 1; i < m; i++) {
    //     dp[0][i] = dp[0][i - 1] + cost[0][i];
    // }
    // for (int j = 1; j < n; j++) {
    //     dp[j][0] = dp[j - 1][0] + cost[j][0];
    // }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = cost[i][j] +
                       min({j - 1 < 0 ? INT_MAX : dp[i][j - 1],
                            i - 1 < 0 or j - 1 < 0 ? INT_MAX : dp[i - 1][j - 1],
                            i - 1 < 0 ? INT_MAX : dp[i - 1][j]});
        }
    }
    return dp[n - 1][m - 1];
}
int main() {
    vector<vector<int>> cost = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};

    cout << minCostPathDP(cost);
    return 0;
}
