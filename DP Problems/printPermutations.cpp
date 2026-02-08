#include <bits/stdc++.h>
using namespace std;


const int P = 100, Q = 100, R = 100;
int dp[P][Q][R][3];

/**
 *
 * when there is no restriction
 */
int countWays1(int p, int q, int r) {
    if (p < 0 or q < 0 or r < 0) return 0;

    if (p == 1 and q == 0 and r == 0) return 1;
    if (p == 0 and q == 1 and r == 0) return 1;
    if (p == 0 and q == 0 and r == 1) return 1;
    int ans = 0;
    ans = countWays1(p - 1, q, r) + countWays1(p, q - 1, r) +
          countWays1(p, q, r - 1);
    return ans;
}

/**
 *
 * when you can't put the similar color together
 */

int countWays(int p, int q, int r, int curr) {
    if (p < 0 or q < 0 or r < 0) return 0;

    if(dp[p][q][r][curr] != -1) return dp[p][q][r][curr];

    if (p == 1 and q == 0 and r == 0 and curr == 0) return 1;
    if (p == 0 and q == 1 and r == 0  and curr == 1) return 1;
    if (p == 0 and q == 0 and r == 1 and curr == 2) return 1;

    int ans = 0;
    if (curr == 0) {
        ans += countWays(p - 1, q, r, 1) + countWays(p - 1, q, r, 2);
    }

    if (curr == 1) {
        ans += countWays(p, q - 1, r, 0) + countWays(p, q - 1, r, 2);
    }

    if (curr == 2) {
        ans += countWays(p, q, r - 1, 1) + countWays(p, q, r - 1, 0);
    }

    dp[p][q][r][curr] = ans;
    return ans;
}




int main() {
    int p = 2, q = 1, r = 1;

    fill_n(&dp[0][0][0][0], P*R*Q*3, -1);
    int ans = countWays(p, q, r, 0) + countWays(p, q, r, 1) + countWays(p, q, r, 2);
    cout << ans;
}