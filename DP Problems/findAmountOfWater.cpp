#include <bits/stdc++.h>
using namespace std;

float solve(int k, int r, int c) {
    if (r == 1) return min(1, k);
    queue<float> q;
    q.push(k);
    for (int i = 0; i < r - 1; i++) {
        float last = 0.0;
        queue<float> q1;
        int size = q.size();
        for (int j = 0; j < size + 1; j++) {
            float temp = 0.0;
            if (q.size() != 0) {
                temp = q.front();
                q.pop();
                temp = max(temp - 1.0, 0.0);
            }
            q1.push(temp / 2.0 + last);
            last = temp / 2.0;
        }
        q = q1;
    }
    for (int i = 0; i < c - 1; i++) {
        q.pop();
    }
    return min(q.front(), 1.f);
}
int main() {
    int k = 3, r = 2, c = 1;
    cout << solve(k, r, c);
}