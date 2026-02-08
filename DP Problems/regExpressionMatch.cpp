#include <bits/stdc++.h>
using namespace std;

bool solveDP(string& s, string& p) {
    int n = s.size();
    int m = p.size();
    bool dp[n + 1][m + 1];
    fill_n(&dp[0][0], (n + 1) * (m + 1), false);

    dp[0][0] = true;
    for (int i = 2; i <= m; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = dp[0][i - 2];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] or p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] =
                    dp[i][j - 2] or (dp[i-1][j] and
                                     (s[i - 1] == p[j - 2] or p[j - 2] == '.'));
            }
        }
    }
    return dp[n][m];
}

int main() {
    string s = "abb";
    string p = "a.*";
    cout << solveDP(s, p);
    return 0;
}