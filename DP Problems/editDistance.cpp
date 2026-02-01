#include <bits/stdc++.h>
using namespace std;

/**
 * dp[i][j]=min operations to convert s1[0....i-1]-> s2[0...j-1]
 * delete form s1 so just ignore last ind----> dp[i][j]=dp[i-1][j]
 * INSERT(insert s2’s last character into s1) --->dp[i][j]=dp[i][j-1]
 * replace(change s1[i-1] into s2[j-1])---> dp[i][j]=dp[i-1][j-1]
 */
int editDP(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    int dp[n + 1][m + 1];
    fill_n(&dp[0][0], (n + 1) * (m + 1), 0);
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1+min(
                    {dp[i - 1][j] , dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[n][m];
}
int main(){
     string s1 = "abcd";
    string s2 = "bcfe";

    cout << editDP(s1, s2);

    return 0;
}