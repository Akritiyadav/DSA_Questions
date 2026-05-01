#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr) {
    int n = arr.size();

    vector<int> smaller(n, -1);

    int mini = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[mini]) {
            mini = i;
        } else {
            smaller[i] = mini;
        }
    }

    vector<int> greater(n, -1);

    int max = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= arr[max]) {
            max = i;
        } else {
            greater[i] = max;
        }
    }

    for (int i = 0; i < n; i++) {
        if (smaller[i] != -1 && greater[i] != -1) {
            return {arr[smaller[i]], arr[i], arr[greater[i]]};
        }
    }

    return {};
}

int main() {
     vector<int> arr = {12, 11, 10, 5, 6, 2, 30};
    vector<int> res = solve(arr);
    for (int x : res)
        cout << x << " ";
    return 0;
}