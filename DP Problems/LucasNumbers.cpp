#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 2;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
    // return solve(n-1)+solve(n-2);
}
/**
 * T(n)=T(n-1)+T(n-2)+c
 * T(n)=T(n-2)+T(n-3)+c+T(n-3)+T(n-4)+c+c
 *
 */
