#include <bits/stdc++.h>
using namespace std;
/**
 * c(n)=sigma (c(i)*c(n-i-1)) where i in [0... n-1]
 */
int catalan(int n) {
    if (n == 0 || n == 1) return 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += catalan(i) * catalan(n - i - 1);
    }
    return sum;
}

int catalanTopDown(int n, vector<int>& dp) {
    if (n == 0 || n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += catalanTopDown(i, dp) * catalanTopDown(n - i - 1, dp);
    }
    return dp[n] = sum;
}

int catalanDp(int n) {
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}
int main() {
    int n = 4;
    vector<int> dp(n + 1, -1);
    // cout << catalanTopDown(n, dp) << " ";
    cout << catalan(n);
    return 0;
}