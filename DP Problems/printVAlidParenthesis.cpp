#include <bits/stdc++.h>
using namespace std;

/**
 * ((()))
 * ()()()  ----1
 * (())()
 * ()(())
 * (()())
 */
int printParenthesis(int totalOpen, int open, int maxOpenAllowed, int curr) {
    if (curr == 2 * maxOpenAllowed) {
        return 1;
    }
    int ans = 0;
    if (open > 0) {
        ans += printParenthesis(totalOpen, open - 1, maxOpenAllowed, curr + 1);
    }
    if (totalOpen < maxOpenAllowed) {
        ans +=
            printParenthesis(totalOpen + 1, open + 1, maxOpenAllowed, curr + 1);
    }
    return ans;
}
const int a = 100;
const int b = 100;
const int c = 100;
int arr[a][b][c];
int printParenthesisDP(int totalOpen, int open, int n, int s) {
    if (s == 2 * n) {
        return 1;
    }
    if (arr[totalOpen][open][s] != -1) return arr[totalOpen][open][s];

    int sum = 0;
    if (open > 0) {
        sum += printParenthesisDP(totalOpen, open - 1, n, s + 1);
    }
    if (totalOpen < n) {
        sum += printParenthesisDP(totalOpen + 1, open + 1, n, s + 1);
    }
    arr[totalOpen][open][s]=sum;
    return sum;
}

int main() {
    int n = 3;
   fill_n(&arr[0][0][0],a*b*c,-1); 
   cout<< printParenthesisDP(0, 0, n, 0);
   return 0;
}