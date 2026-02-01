#include <bits/stdc++.h>
using namespace std;

/**
 *
 */
int jump(vector<int>& arr) {
    int n = arr.size();
    int dp[n];
    fill_n(&dp[0], n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (j + arr[j] >= i) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}

int main(){
    vector<int> arr = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    cout <<jump(arr);
    return 0;
}