#include <bits/stdc++.h>
using namespace std;

/**
 * solve(n)=(n-1)*solve(n-2)  when swapping with one element(2 ele swapped with each other and n-2 left)
 * then again for n-2 ele tey will dearrange in themselves in solve(n-2) ways
 * 
 * solve(n)=solve(n-1)*(n-1)   n-1 elementa are dearranging in themselves 
 * and then last elemnet element will arrange in n-1 ways---->
 * so dp[n]=(n-1)*(dp[n-2]+dp[n-1])
 * 
 */
int solve(int n) {
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]);
    }
    return dp[n];
}

int main(){
    int n=5;
    cout<<solve(n);
}