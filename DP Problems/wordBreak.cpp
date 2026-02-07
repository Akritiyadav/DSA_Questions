#include <bits/stdc++.h>
using namespace std;

bool solve(string& str, set<string>& arr, int n) {
    if (n < 0) return true;
    int i = n;
    bool ans = false;
    string temp;
    for (i = n; i >= 0; i--) {
        temp = str[i] + temp;
        if (arr.count(temp)) {
            ans = solve(str, arr, i - 1);
            if (ans) return true;
        }
    }
    return false;
}

/**
 * akriti
 */
bool solveDP(string& str, set<string>& arr) {
    int n = str.size();
    bool dp[n + 1];
    fill_n(dp, n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            string cut = str.substr(j, i - j);
            dp[i] = dp[i] || (arr.count(cut) && dp[j]);
        }
    }
    return dp[n];
}

int main() {
    string s = "ilike";
    vector<string> dictionary = {"i", "like", "gfg"};
    set<string> st;
    for (auto it : dictionary) {
        st.insert(it);
    }
    cout << solveDP(s, st);
}