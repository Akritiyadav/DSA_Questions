#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr, int sum, int ind, vector<vector<int>>& dp) {
    if (sum == 0) return true;
    if (ind < 0) return false;
    // if (ind == 0) {
    //     return sum == arr[0];
    // }
    if (dp[ind][sum] != -1) return dp[ind][sum];
    bool take = false;
    if (arr[ind] <= sum) {
        take = solve(arr, sum - arr[ind], ind - 1, dp);
    }
    bool notTake = solve(arr, sum, ind - 1, dp);
    dp[ind][sum] = take || notTake;
    return dp[ind][sum];
}
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return solve(arr, sum, n - 1, dp);
}

int subsetSumDP(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j) {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

/**
 * f(n,sum)=f(n-1,sum) or f(n-1,sum-arr[n])
 */
int SumDP(vector<int>& arr, int sum) {
    int n = arr.size();
    bool dp[n + 1][sum + 1];
    fill_n(&dp[0][0], (sum + 1) * (n + 1), false);
    for (int i = 0; i <= sum; i++) {
        dp[0][i] = false;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - arr[i - 1] >= 0) {
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    dp[n][sum];
}
int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 34;

    if (SumDP(arr, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
