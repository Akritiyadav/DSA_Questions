#include <bits/stdc++.h>
using namespace std;
/**
 * f(n,r)=  f(n-1,r-1)+f(n-1,r);
 *  dp[n][r]=dp[n-1][r-1]+dp[n-1][r]
 */
int fact(int n) {
    if (n == 0 || n == 1) return 1;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
int binomialCoefDP(int n, int r) {
    vector<vector<int>> dp(n + 1, vector<int>(r + 1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= r; i++) {
        dp[0][i] = 0;
    }
     dp[0][0]=1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= r; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}

int main() {
    int n = 100, r = 2;
    cout << binomialCoefDP(n, r);
}