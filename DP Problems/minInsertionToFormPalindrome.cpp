#include <bits/stdc++.h>
using namespace std;

int solve(string& s, int start, int end) {
    if (start >= end) {
        return 0;
    }
    if (s[start] == s[end]) {
        return solve(s, start + 1, end - 1);
    }
    return 1 + min(solve(s, start + 1, end), solve(s, start, end - 1));
}
int solveDP(string& s, int start, int end, vector<vector<int>>& dp) {
    if (start >= end) {
        return 0;
    }
    if (dp[start][end] != -1) return dp[start][end];
    if (s[start] == s[end]) {
        return dp[start][end] = solveDP(s, start + 1, end - 1, dp);
    }
    return dp[start][end] = 1 + min(solveDP(s, start + 1, end, dp),
                                    solveDP(s, start, end - 1, dp));
}

int solveBottom(string& s) {
    int n = s.size();
    string a = s;
    string b = s;
    reverse(b.begin(), b.end());
    int dp[n + 1][n + 1];
    fill_n(&dp[0][0], (n + 1) * (n + 1), 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main() {
    string s = "aba";
    int n = s.size();
    // int start = 0, end = n - 1;
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << solveDP(s, start, end, dp);
    int k = solveBottom(s);
    cout << n - k;
}