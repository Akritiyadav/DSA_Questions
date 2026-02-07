#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    int n = arr.size();
    int dp[n];
    fill_n(&dp[0], n, 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(arr[j] - arr[i]) == 1) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
     vector<int> arr = {10, 9, 4, 5, 4, 8, 6};

    cout << solve(arr);

    return 0;
}