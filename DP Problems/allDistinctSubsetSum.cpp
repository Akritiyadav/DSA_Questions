#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int ind, int sum, set<int>& st) {
    if (ind < 0) {
        st.insert(sum);
        return;
    }
    solve(arr, ind - 1, sum + arr[ind], st);
    solve(arr, ind - 1, sum, st);
}

vector<int> solveDP(vector<int>& arr) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    bool dp[n + 1][sum + 1];
    fill_n(&dp[0][0], (n + 1) * (sum + 1), false);
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            bool notTake = dp[i - 1][j];
            bool Take = false;
            if (arr[i - 1] <= j) {
                Take = dp[i - 1][j - arr[i - 1]];
            }
            dp[i][j] = (Take or notTake);
        }
    }
    vector<int> res;
    for (int i = 0; i <= sum; i++) {
        if (dp[n][i]) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 2,3,4,5,6};
    int n = arr.size();
    vector<int> ans = solveDP(arr);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}
