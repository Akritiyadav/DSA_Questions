#include <bits/stdc++.h>
using namespace std;

/**
 * f(arr,n,available)=max(
 * f(arr,n-1,available),f(arr,n,availabe-n)+arr[n]
 * )
 */
int solve(vector<int>& price, int ind, int available) {
    if (available == 0) return 0;
    if (ind <= 0) return 0;
    int notTaken = solve(price, ind - 1, available);
    int taken = 0;
    if (available - ind >= 0) {
        taken = solve(price, ind, available - ind) + price[ind - 1];
    }
    return max(taken, notTaken);
}

int solveDP(vector<int>&price){
    int n=price.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int notTaken=dp[i-1][j];
            int taken=0;
            if(j-i>=0){
                taken=dp[i][j-i]+price[i-1];
            }
            dp[i][j]=max(taken,notTaken);
        }
    }
     return dp[n][n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    cout << solveDP(price);
    return 0;
}
