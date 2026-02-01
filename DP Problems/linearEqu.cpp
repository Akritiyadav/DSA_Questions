#include <bits/stdc++.h>
using namespace std;
/**
 * a1 +a2+a3....+an=N, where N>=n ,a1,a2,a3....an are >=0
 * find out the no of solution
 * Given N and n
 *
 *
 * f(x,y)= sigma f(x-1,y-i), where i in [0,1,2....y]
 * f(1,15)= f(0,15)+f(0,14)+f(0,13).....f(0,0)
 * 
 * C(N + n − 1, n − 1) formula for n>=0
 * C(N-1,n-1)   if n>=1
 */

int solve(int n, int N) {
    if (N == 0) return 1;
    if (n <= 0) return 0;
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        cnt += solve(n - 1, N - i);
    }
    return cnt;
}
int solveDP(int n, int N) {
    vector<vector<int>> dp(n + 1, vector<int>(N + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    return dp[n][N];
}

//for n>=1
int solution(int n, int N){
    if(n>N) return 0;
    if(n==N) return 1;
    if(n==0 && N!=0) return 0;
    int res=0;
    for(int i=1;i<=N;i++){
        res+=solution(n-1,N-i);
    }
    return res;
}

int solutionDP(int n, int N){
    vector<vector<int>>dp(n+1,vector<int>(N+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=j;k++){
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }
    return dp[n][N];
}
int main() {
    int n = 4, N = 14;
    cout << solutionDP(n, N);
}