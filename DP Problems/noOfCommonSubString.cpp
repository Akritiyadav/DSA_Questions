#include <bits/stdc++.h>
using namespace std;
int solve(string s, string t, int n, int m) {
    if (n < 0 or m < 0) return 0;
    int ans = 0;
    while (n >= 0 && m >= 0 && s[n] == t[m]) {
        ans++;
        n--;
        m--;
    }
    if (n < 0 or m < 0) {
        return ans;
    }
    int a=solve(s,t,n-1,m);
    int b=solve(s,t,n,m-1);
    return max({ans,a,b});
}
int subStringDP(string s, string t) {
    int n = s.size();
    int m = t.size();
    int dp[n + 1][m + 1];
    fill_n(&dp[0][0], (n+1) * (m+1), 0);
    int ans = 0;
    // for (int i = 0; i <= m; i++) {
    //     dp[0][i] = 0;
    // }
    // for (int i = 0; i <= n; i++) {
    //     dp[i][0] = 0;
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main() {
    string s = "gfgfor", t = "gfg";
    int n=s.size(),m=t.size();
    cout << subStringDP(s, t);
}
/**
 * ddddd.....drrrrr....r
 * (n-1+m-1)!/(n-1)!*(m-1)!
 */