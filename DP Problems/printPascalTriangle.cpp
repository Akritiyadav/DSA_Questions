#include <bits/stdc++.h>
using namespace std;

void printPascalTriangle(int n) {
    queue<int> que1;
    que1.push(1);
    cout << "1" << "\n";
    for (int i = 1; i < n; i++) {
        queue<int> que2;
        int last = 0;
        for (int j = 0; j <= i; j++) {
            int curr = 0;
            if (que1.size()) {
                curr = que1.front();
                que1.pop();
            } else {
                curr = 0;
            }
            cout << (last + curr) << "\t";
            que2.push(last + curr);
            last = curr;
        }
        que1 = que2;
        cout << "\n";
    }
}
int main() {
    int n = 5;
    printPascalTriangle(n);
    return 0;
}