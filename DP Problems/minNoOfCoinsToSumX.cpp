#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& coins, int sum, int ind) {
    if (sum == 0) return 0;
    if (ind < 0) return INT_MAX;
    long long NotTake = solve(coins, sum, ind - 1);
    long long take = INT_MAX;
    if (sum - coins[ind] >= 0) {
        take = 1 + solve(coins, sum - coins[ind], ind);
    }
    return min(take, NotTake);
}

long long  countDP(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
    for (int i = 0; i <= sum; i++) {
        dp[0][i] = INT_MAX;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            long long a = INT_MAX, b = INT_MAX;
            a = dp[i - 1][j];
            if (j - coins[i - 1] >= 0) {
                b = 1 + dp[i][j - coins[i - 1]];
            }
            dp[i][j] = min(a, b);
        }
    }
    return dp[n][sum];
}
int main() {
    vector<int> coins = {25,10,5};
    int sum = 30;
    cout << solve(coins, sum, coins.size() - 1) << endl;
    cout << countDP(coins, sum);
    return 0;
}
