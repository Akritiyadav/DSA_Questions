#include <bits/stdc++.h>
using namespace std;

int maxLenZeroSum(vector<int>& arr) {
    int n = arr.size();

    // Maps prefix Sum-> earliest index where this sum was seen
    unordered_map<int, int> seen;

    int maxi = 0;
    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Rule 1: whole subarray from 0..i is zero sum
        if (prefixSum == 0) {
            maxi = i + 1;
        }

        // rule 2: this prefix sum was seen before at index j
        // subarray from j+1 to i is zero sum
        else if (seen.find(prefixSum) != seen.end()) {
            int j = seen[prefixSum];
            maxi = max(maxi, i - j);
        }

        // only store the first occurrence -earlier index=longer subarray
        else {
            seen[prefixSum] = i;
        }  
    } 
    return maxi;
}



int main() {
    vector<int> arr1 = {9, -3, 3, -1, 6, -5};
    cout << maxLenZeroSum(arr1) << "\n"; // Output: 5

    vector<int> arr2 = {6, -2, 2, -8, 1, 7, 4, -10};
    cout << maxLenZeroSum(arr2) << "\n"; // Output: 8
}
// Time:  O(n) — single pass
// Space: O(n) — for the HashMap