#include <bits/stdc++.h>
using namespace std;

/**
 * s1,s2--> string
 *  if(s1[x]==s2[y]) f(x,y)=f(x-1,y-1)+1
 * else f(x,y)=max(f(x,y-1) f(x-1,y))
 *
 */

 
int solveDP(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    int dp[n + 1][m + 1];
    fill_n(&dp[0][0], (n + 1) * (m + 1), 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}