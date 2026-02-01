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

bool solveDP(string& str, set<string>& arr) {
    int n = str.size();
    bool dp[n + 1];
    fill_n(dp, n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        /**starting from zero cut all the possible string as second string and check second
         * as well as dp[j] {which is basically first cut} exist 
        **/
        for (int j = 0; j <= i; j++) {
            string second = str.substr(j, i - j); 
            if (dp[i]) break; // dp[i] has already been found that means i length is possible, so no need to compute more
            dp[i] = dp[j] and arr.count(second); // by taking second as last cut and checking dp[j] exist in some cuts
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
    st.insert("");
    cout << solveDP(s, st);
}