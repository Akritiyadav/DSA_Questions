#include <bits/stdc++.h>
using namespace std;

/**
 * Suppose we choose key r as root in range [i…j]
Then:
Left subtree = [i … r-1]
Right subtree = [r+1 … j]

   cost(i, j) = cost(i, r-1) +cost(r+1, j) + sum(freq[i…j])  //Why add
sum(freq[i…j])?  Because every node except root moves one level deeper

 */

int recur(int i, int j, vector<int>& freq) {
    if (i > j) return 0;
    if (i == j) return freq[i];

    int ans = INT_MAX;
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += freq[k];
    }

    for (int r = i; r <= j; r++) {
        int cost = recur(i, r - 1, freq) + recur(r + 1, j, freq) + sum;
        ans = min(ans, cost);
    }
    return ans;
}

int solve(int i, int j, vector<int>& freq, vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (i == j) return freq[i];

    if (dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += freq[k];
    }

    for (int r = i; r <= j; r++) {
        int cost = solve(i, r - 1, freq, dp) + solve(r + 1, j, freq, dp) + sum;
        ans = min(ans, cost);
    }
    dp[i][j] = ans;
    return ans;
}


int main() {
    vector<int> keys = {10, 12};
    vector<int> freq = {34, 50};
    int n = keys.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout <<recur(0,n-1,freq);
    cout << solve(0, n - 1, freq, dp);
    return 0;
}