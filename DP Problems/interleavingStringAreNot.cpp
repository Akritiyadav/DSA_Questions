#include <bits/stdc++.h>
using namespace std;

/**
 * If the first character of s3 matches the first character of s1, we move one
character ahead in s1 and s3 and recursively check. If the first character of s3
matches the first character of s2, we move one character ahead in s2 and s3 and
recursively check. If none of the two characters match, return false. If any of
the above function returns true or s1, s2 and s3 are empty then return true else
return false.

  Characters used from s1 = i + 1   Characters used from s2 = j + 1
  , characters used in s3:  (i + 1) + (j + 1) = i + j + 2
  Last index of s3 used:  k = (i + j + 2) - 1 = i + j + 1

  int Tabulation:- char in s1 used i and in s2 j so last ind of s3= k=i+j-1;

 */

bool isInterleaveRec(string& s1, string& s2, string& s3, int i, int j) {
    if (i < 0 && j < 0) return true;

    int k = i + j + 1;

    bool a = false, b = false;

    if (i >= 0 && s1[i] == s3[k]) {
        a = isInterleaveRec(s1, s2, s3, i - 1, j);
    }

    if (j >= 0 && s2[j] == s3[k]) {
        b = isInterleaveRec(s1, s2, s3, i, j - 1);
    }

    return a || b;
}

bool solve(string& s1, string& s2, string& s3, int i, int j,
           vector<vector<int>>& dp) {
    if (i < 0 && j < 0) return true;

    int k = i + j + 1;
    if (dp[i][j] != -1) return dp[i][j];

    bool a = false, b = false;

    if (i >= 0 && s1[i] == s3[k]) {
        a = solve(s1, s2, s3, i - 1, j, dp);
    }

    if (j >= 0 && s2[j] == s3[k]) {
        b = solve(s1, s2, s3, i, j - 1, dp);
    }
    dp[i][j] = a || b;
    return dp[i][j];
}

int solveDP(string& s1, string& s2, string& s3) {
    int m = s1.size(), n = s2.size();

    if (m + n != s3.size()) return false;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    // Fill first row (s1 is empty)
    for (int j = 1; j <= n; j++)
        dp[0][j] = (s2[j - 1] == s3[j - 1]) && dp[0][j - 1];

    // Fill first column (s2 is empty)
    for (int i = 1; i <= m; i++)
        dp[i][0] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][0];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int k = i + j - 1;
            dp[i][j] = (s1[i - 1] == s3[k] && dp[i - 1][j]) ||
                       (s2[j - 1] == s3[k] && dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "AAB";
    string s2 = "AAC";
    string s3 = "AAAABC";

    if (s1.size() + s2.size() != s3.size()) {
        cout << "false\n";
        return 0;
    }
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    cout << (solve(s1, s2, s3, s1.size() - 1, s2.size() - 1, dp) ? "true"
                                                                 : "false")
         << endl;

     cout << (solveDP(s1, s2, s3) ? "true" : "false") << endl;
}