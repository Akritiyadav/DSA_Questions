#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

void largestDivisibleSubsetDP(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<pii> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = {1, i};
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0 && dp[j].first + 1 > dp[i].first) {
                dp[i] = {dp[j].first + 1, j};
            }
        }
    }
    int last = 0, len = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i].first > len) {
            last = i;
            len = dp[i].first;
        }
    }
    while (dp[last].first != 1) {
        cout << arr[last] << " ";
        last = dp[last].second;
    }
    cout << arr[last];
}
int main() {
    vector<int> arr = {1, 16, 7, 8, 4};
    largestDivisibleSubsetDP(arr);
}