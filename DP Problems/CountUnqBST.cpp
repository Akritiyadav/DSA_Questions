#include <bits/stdc++.h>
using namespace std;

int countBST(int n) {
    if (n == 0 || n == 1) return 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += countBST(i - 1) * countBST(n - i);
    }
    return sum;
}

/**
 * x   parent =[1 2 ... x]
 *      left= [  0,1....x-1]
 *      right=[x-1,x-2....0]
 *
 */
int countBSTDP(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
int main() { cout << countBSTDP(10); }