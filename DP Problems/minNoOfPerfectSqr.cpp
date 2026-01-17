#include <bits/stdc++.h>
using namespace std;

/**
 * for any no x
 * f(x)= min[1+f(x-i^2),f(x)] , where i in [1,2,.....sqrt(x)]
 */

/**
 * Time complexity analysis
 * sqrt(1)+sqrt(2)....sqrt(n)<=sqrt(n)+sqrt(n)......+sqrt(n)
 * <=n*sqrt(n);
 *
 * integration of (sqrt(x)) where limit of x is 1 to n
 *
 */
int solveTopDown(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int ans = INT_MAX;
    for (int i = 1; i <= sqrt(n); i++) {
        ans = min(ans, 1 + solveTopDown(n - i * i, dp));
    }
    return dp[n] = ans;
}

int numOfSqursDP(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {  // j<=sqrt(i) or j*j<=i
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
    }
    return dp[n];
}
int main() {
    int n = 6;
    vector<int> dp(n + 1, -1);
    cout << numOfSqursDP(n);
}