#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> jobs, int n) {
    if (n < 0) return 0;
    int take = 0, notTake = 0;
    int i = n - 1;
    while (i >= 0 && jobs[i][1] > jobs[n][0]) {
        i--;
    }
    take = jobs[n][2] + solve(jobs, i);
    notTake = solve(jobs, n - 1);
    return max(take, notTake);
}

int solveDP(vector<vector<int>> jobs) {
    int n = jobs.size();
    int dp[n];
    fill_n(&dp[0], n, 0);
    dp[0] = jobs[0][2];
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && jobs[j][1] > jobs[i][0]) {
            j--;
        }
        dp[i] = max(dp[i-1], jobs[i][2] + (j < 0 ? 0 : dp[j]));
    }
    return dp[n - 1];
}

int main() {
    vector<vector<int>> jobs = {
        {1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), [](auto a, auto b) { return a[1] < b[1]; });
    cout << solveDP(jobs);
}
