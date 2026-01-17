#include <bits/stdc++.h>
using namespace std;

int recur(int n){
    if(n==0 || n==1) return 1;
    return recur(n-1)+recur(n-2);
}

int funTopDown(int n,vector<int>&dp){
   if(n==0 || n==1) return 1;
   if(dp[n]!=-1) return dp[n];
   dp[n]=funTopDown(n-1,dp)+funTopDown(n-2,dp);
   return dp[n];
}

int funBottomUp(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main() {
    int n = 8;
    vector<int>dp(n+1,-1);
    int val = funTopDown(n,dp);
    cout << val;
    return 0;
}
