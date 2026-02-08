#include <bits/stdc++.h>
using namespace std;

int wordCountDP(string str) {
    if (str[0] == '0') return 0;
    int n = str.size();
    int dp[n + 1];
    fill_n(&dp[0], n + 1, 0);
    dp[1] = 1;
    string s = str.substr(0, 2);
    if (/**stoi(s) >= 10 &&**/ stoi(s) <= 26 && str[1] != '0') {
        dp[2] = 2;
    } else if ((str[1] != '0') or (s == "10" or s == "20")) {
        dp[2] = 1;
    }
    for (int i = 3; i <= n; i++) {
        if (str[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        string s = str.substr(i - 2, 2);
        if (stoi(s) >= 10 && stoi(s) <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}
int main() {
     cout << wordCountDP("121"); 
}