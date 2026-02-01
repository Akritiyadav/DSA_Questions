#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& grid, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    if(grid[0][0]==1) return 0;
    if (i < 0 or j < 0) return 0;
    if (i == 0 && j == 0) return 1;
    int ans = 0;
    if (grid[i][j] != 1) {
        ans = solve(grid, i - 1, j) + solve(grid, i, j - 1);
    }
    return ans;
}

int solveDP(vector<vector<int>>& grid) {
    if(grid[0][0]==1) return 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0]=1;
    for (int i = 1; i < m; i++) {
        if (grid[0][i] != 1) {
            dp[0][i] = dp[0][i-1];
        }
    }
    for (int i = 1; i < n; i++) {
        if (grid[i][0] != 1) {
            dp[i][0] = dp[i-1][0];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(grid[i][j]!=1){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[n-1][m-1];
}
int main() {
    vector<vector<int>> grid = {{1, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int n = grid.size();
    int m = grid[0].size();
    cout << solveDP(grid);
}