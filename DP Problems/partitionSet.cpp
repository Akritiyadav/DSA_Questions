#include <bits/stdc++.h>
using namespace std;

bool solveDP(vector<int>& arr) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 != 0) return false;
    int target = sum / 2;
    bool dp[n + 1][target + 1];
    fill_n(&dp[0][0], (n + 1) * (target), false);

    for (int i = 0; i <= target; i++) {
        dp[0][i] = false;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i - 1] <= j) {
                take = dp[i - 1][j - arr[i - 1]];
            }
            dp[i][j]=take or notTake;
        }
    }
    return dp[n][target];
}

int main(){
     vector<int> arr = { 1, 5, 11, 5};
    if (solveDP(arr)) {
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
    return 0;
}