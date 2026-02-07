#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k) {
    int dp[n + 1][m + 1];
    fill_n(&dp[0][0], (n + 1) * (m + 1), 0);

    for (int i = 0; i <= m; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j - 1];
            for (int t = 1; t <= min(i, k); t++) {
                dp[i][j] += dp[i - t][j - 1];
            }
        }
    }
    return dp[n][m];
}

int main(){
    int n=3,m=3,k=2;
    cout<<solve(n,m,k);
}