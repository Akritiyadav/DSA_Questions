#include <bits/stdc++.h>
using namespace std;

/**
 * 1 2 3 4 5 6, 2 1 4 3 6 5
 * 2 1 4 3 6 5
 *
 */

int solve(vector<int>& arr, int ind) {
    int n = arr.size();
    if (n < 0) return 0;
    int a = arr[ind] + max(solve(arr, ind - 3), solve(arr, ind - 2));
    int b = solve(arr, ind - 1);
    return max(a, b);
}


// int solve(vector<int> arr) {
//     int n = arr.size();
//     if (n == 0) return 0;
//     if (n == 1) return arr[0];
//     int dp[n + 1];
//     fill_n(&dp[0], n + 1, 0);
//     dp[0] = 0;
//     dp[1] = arr[0];
//     for (int i = 2; i <= n; i++) {
//         dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
//     }
//     return dp[n];
// }


int houseRobberDP(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = arr[i] +
                max(i - 2 >= 0 ? dp[i - 2] : 0, i - 3 >= 0 ? dp[i - 3] : 0);
        dp[i] = max(dp[i], dp[i - 1]);
    }
    return max(dp[n - 2], dp[n - 1]);
    // return dp[n - 1];
}

int main() {
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << houseRobberDP(hval) << endl;
    return 0;
}
