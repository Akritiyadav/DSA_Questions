#include <bits/stdc++.h>
using namespace std;

int solve(int W, vector<int>& profit, vector<int>& wt, int n) {
    if (n < 0) return 0;
    if (W == 0) return 0;
    int a = 0, b = 0;
    if (wt[n] <= W) {
        a = profit[n] + solve(W - wt[n], profit, wt, n - 1);
    }
    b = solve(W, profit, wt, n - 1);
    return max(a, b);
}

int solveDP(int W, vector<int>& prof, vector<int>& wt) {
    int n = wt.size();
    int dp[n + 1][W + 1];
    fill_n(&dp[0][0], (W + 1) * (n + 1), 0);
    // for (int i = 0; i <= W; i++) {
    //     dp[0][i] = 0;
    // }
    // for (int i = 0; i <= n; i++) {
    //     dp[i][0] = 0;
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            int a = 0, b = 0;
            b = dp[i - 1][j];
            if (wt[i - 1] <= j) {
                a = prof[i - 1] + dp[i-1][j - wt[i - 1]];
            }
            dp[i][j] = max(a, b);
        }
    }
    vector<int> ans;
    int i = n, j = W;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i = i - 1;
        } else {
            ans.push_back(wt[i - 1]);
            i = i - 1;
            j = j - wt[i - 1];
        }
    }
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return dp[n][W];
}

int main() {
     vector<int> val = {1,2,3}, wt = {4,5,6};
    int capacity = 3;
    cout << solveDP(capacity, val, wt) << endl;
    return 0;
}