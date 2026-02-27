#include <bits/stdc++.h>

using namespace std;

using ll = long long;
/**
 *
 */
int solve(int n, vector<vector<int>>& ladders, vector<vector<int>>& snakes) {
    vector<ll> dp(n + 1, INT_MAX);
    dp[1] = 0;
    vector<ll> ladder1(n + 1, -1);
    for (int i = 0; i < ladders.size(); i++) {
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

// using dijkstra algo

using pii = pair<int, int>;
int solve(vector<int>& graph) {
    int n = graph.size();
    vector<int> ans(n + 1, INT_MAX);
    ans[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1});

    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        int a = top.first;
        int b = top.second;

        for (int i = b + 1; i <= min(b + 6, n); i++) {
            if (i < n and graph[i] != -1 and graph[i] < i) {
                continue;
            }
            if (ans[i] > ans[b] + 1) {
                ans[i] = ans[b] + 1;
                pq.push({ans[i], i});
            }
        }
        if (graph[b] != -1 and graph[b] > b) {
            int newIndex = graph[b];
            ans[newIndex] = min(ans[newIndex], ans[b]);
            pq.push({ans[newIndex], newIndex});
        }
    }
    return ans[n];
}

int main() {
    // int n = 30;
    // vector<vector<int>> ladders = {{2, 21}, {4, 7}, {10, 25}, {19, 28}};
    // vector<vector<int>> snakes = {{26, 0}, {20, 8}, {16, 3}, {18, 6}};
    // cout<<solve(n,ladders,snakes);

    int n = 30;
    vector<int> moves(n, -1);

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
    cout<<solve(moves);
}