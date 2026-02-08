#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& coins, int sum, int ind, vector<vector<int>>& dp) {
    if (sum == 0) return 1;
    if (ind < 0) {
        return 0;
    }
    if (dp[ind][sum] != -1) return dp[ind][sum];
    int take = 0;
    if (coins[ind] <= sum) {
        take = solve(coins, sum - coins[ind], ind, dp);
    }
    int notTake = solve(coins, sum, ind - 1, dp);
    return dp[ind][sum] = take + notTake;
}
int count(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return solve(coins, sum, n - 1, dp);
}


int countDP(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int s = 0; s <= sum; s++) {
        dp[0][s] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - coins[i - 1] >= 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << countDP(coins, sum);
    return 0;
}