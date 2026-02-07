#include <bits/stdc++.h>
using namespace std;

int solve(string s, int start, int end) {
    if (start == end) return 1;
    if (start > end) return 0;
    int ans = 0, a = 0, b = 0;
    if (s[start] == s[end]) {
        return 2 + solve(s, start + 1, end - 1);
    }
    a = solve(s, start + 1, end);
    b = solve(s, start, end - 1);
    return max(a, b);
}

int solveDP(string& s) {
    string a = s;
    string b = s;
    int n = s.size();
    reverse(b.begin(), b.end());// after reversing it will be longest common subseq problem
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
    string s = "bbabcbcab";
    int n = s.size();
    cout << solveDP(s);
    return 0;
}
