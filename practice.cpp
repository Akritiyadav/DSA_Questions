#include <bits/stdc++.h>
using namespace std;

int countDP(string str) {
    int n = str.size();
    if (str[0] == '0') return 0;
    int dp[n + 1];
    fill_n(&dp[0], n + 1, 0);
    dp[1] = 1;
    string temp = str.substr(0, 2);
    if (stoi(temp) <= 26 && str[1] != '0') {
        return 2;
    } else if ((str[1] != '0') or (temp == "10" or temp == "20")) {
        return 1;
    }
    for (int i = 3; i <= n; i++) {
        if (str[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        string temp = str.substr(i - 2, 2);
        if (stoi(temp) >= 10 && stoi(temp) <= 26) {
            dp[i] += dp[-2];
        }
    }
    dp[n];
}

/**
 * u have n boys and n girls, out of which some boys have problem with some girls  and vice versa 
 * find out the no of ways , you can send them on trip where no 2 trips have same boy and girl together 
 */