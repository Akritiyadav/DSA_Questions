#include <bits/stdc++.h>
using namespace std;
/**
 * if we solve any problem with -1 indexing then insted of DP we use map
 * map<vector<int>,int>mp
 */
int solve(int n, int m, int back, vector<int>& a, vector<int>& b) {
    if (n < 0 or m < 0) return 0;
    int take = 0, notTake = 0;
    if (a[n] == b[m] && (back == -1 or a[n] < a[back])) {
        take = 1 + solve(n - 1, m - 1, n, a, b);
    }
    notTake = max(solve(n - 1, m, back, a, b), solve(n, m - 1, back, a, b));
    return max(take, notTake);
}

const int N = 100, M = 100, K = 100;
int dp[N][M][K];
int solveDP(int n, int m, int back, vector<int>& a, vector<int>& b) {
    if (n < 0 or m < 0) return 0;
    if (dp[n][m][back] != -1) return dp[n][m][back];
    int take = 0, notTake = 0;
    if (a[n] == b[m] && a[n] < back) {
        take = 1 + solveDP(n - 1, m - 1, a[n], a, b);
    }
    notTake = max(solveDP(n - 1, m, back, a, b), solveDP(n, m - 1, back, a, b));
    dp[n][m][back] = max(take, notTake);
    return dp[n][m][back];
}

int main() {
    vector<int> a = {3, 4, 9, 1};
    vector<int> b = {5, 3, 8, 9, 10, 2, 1};
    int n = a.size();
    int m = b.size();
    int mx1 = *max_element(a.begin(), a.end());
    int mx2 = *max_element(b.begin(), b.end());
    fill_n(&dp[0][0][0], N * M * K, -1);
    // cout << solve(n - 1, m - 1, -1, a, b);
    cout << solveDP(n - 1, m - 1, max(mx1, mx2) + 1, a, b);
    return 0;
}