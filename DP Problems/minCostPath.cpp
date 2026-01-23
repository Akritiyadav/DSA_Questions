#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& cost, int i, int j) {
    if (i == 0 && j == 0) {
        return cost[0][0];
    }
    if (i < 0 || j < 0) return INT_MAX;
    return cost[i][j] + min({solve(cost, i - 1, j), solve(cost, i - 1, j - 1),
                             solve(cost, i, j - 1)});
}
int minCostPath(vector<vector<int>>& cost) {
    int n = cost.size();
    int m = cost[0].size();
    return solve(cost, n - 1, m - 1);
}

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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = cost[i][j];
                continue;
            }
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
