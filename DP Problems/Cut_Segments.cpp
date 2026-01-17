#include <bits/stdc++.h>
using namespace std;

//recursive approach  TC:O(3)^n
int fun(int n, int x, int y, int z) {
    int first=0,second=0,third=0;
    if(n-x>=0) {
        first=fun(n-x,x,y,z)+1;
    } 
    if(n-y>=0) {
        second=fun(n-y,x,y,z)+1;
    } 
    if(n-z>=0) {
        third=fun(n-z,x,y,z)+1;
    } 
    return max ({first,second,third});
}

// top down    TC:O(n)
int funMemo(int n, int x, int y, int z, vector<int>&dp) {
    int first=0,second=0,third=0;
    if(dp[n]!=-1) return dp[n];
    if(n-x>=0) {
        first=funMemo(n-x,x,y,z,dp)+1;
    } 
    if(n-y>=0) {
        second=funMemo(n-y,x,y,z,dp)+1;
    } 
    if(n-z>=0) {
        third=funMemo(n-z,x,y,z,dp)+1;
    } 
    dp[n] =max ({first,second,third});
    return dp[n];
}

// bottom up tc:-O(n)
int funDpBottom(int n, int x, int y ,int z){
    vector<int>dp(n+1);
    
    for(int i=0;i<=n;i++){
        int first=0,second=0,third=0;
        if(i-x>=0){
            first=dp[i-x]+1;
        }
        if(i-y>=0){
            second=dp[i-y]+1;
        }
        if(i-z>=0){
            third=dp[i-z]+1;
        }
       dp[i]= max({first,second,third});
    }
     return dp[n];
}
int main() {
   int  n = 5, x = 5, y = 3, z = 2;
    cout << funDpBottom(n, x, y, z);

    return 0;
}