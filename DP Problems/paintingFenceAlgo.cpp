#include <bits/stdc++.h>
using namespace std;

/**
 * countWays(n) = countWays(n-1)*(k-1) + countWays(n-2)*(k-1)
 * Case 1: Different Color for the Last Post
If we paint the last post a different color from the one before it, we have k-1 choices (all colors except the previous post’s color).
 This means the number of ways to paint the first n-1 posts is multiplied by k-1.

Case 2: Same Color for the Last Two Posts
If the last two posts are the same color, they must differ from the post before them (the third-last post). 
Thus, we have k-1 choices for the last two posts, and the number of ways to paint the first n-2 posts is given by countWays(n-2). 
 * 
 * 
 */
int solve(int n, int k) {
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2]=k*k;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
    }
    return dp[n];
}
int main() {
    int n = 2, k = 4;
    cout << solve(n, k) << endl;
    return 0;
}
