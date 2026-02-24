#include <bits/stdc++.h>

using namespace std;

using ll=long long;
/**
 *
 */
int solve(int n, vector<vector<int>>& ladders, vector<vector<int>>& snakes) {
    vector<ll> dp(n + 1, INT_MAX);
    dp[1] = 0;
    vector<ll> ladder1(n + 1, -1);
    for (int i = 0; i <ladders.size(); i++) {
        ladder1[ladders[i][1]] = ladders[i][0];
    }
    vector<ll> snake1(n + 1, -1);
    for (int i = 0; i < snakes.size(); i++) {
        snake1[snakes[i][0]] = snakes[i][1];
    }

    for (int i = 2; i <= n; i++) {
        if (snake1[i] != -1) {
            continue;
        }
        for (int k = 1; k <= 6; k++) {
            if (i - k >= 1) {
                dp[i] = min(dp[i], dp[i - k] + 1);
            }
        }

        if (ladder1[i] != -1) {
            dp[i] = min(dp[i], dp[ladder1[i]]);
        }
    }
    return dp[n];
}





int main() {
    int n = 30;
    vector<vector<int>> ladders = {{2, 21}, {4, 7}, {10, 25}, {19, 28}};
    vector<vector<int>> snakes = {{26, 0}, {20, 8}, {16, 3}, {18, 6}};
    cout<<solve(n,ladders,snakes);
    
}