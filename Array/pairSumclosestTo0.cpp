#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
    // Step 1: Sort array (important for two pointer)
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size() - 1;

    // bestSum will store our final answer
    int bestSum = INT_MAX;

    while (left < right) {

        // current pair sum
        int sum = arr[left] + arr[right];

        // Step 2: Check if this sum is closer to 0
        if (abs(sum) < abs(bestSum)) {
            bestSum = sum;   // update best answer
        }

        // Step 3: If tie (same distance from 0)
        else if (abs(sum) == abs(bestSum)) {
            bestSum = max(bestSum, sum);  // choose larger sum
        }

        // Step 4: Move pointers
        if (sum < 0) {
            // sum negative → need bigger value → move left forward
            left++;
        } else {
            // sum positive → need smaller value → move right backward
            right--;
        }
    }

    return bestSum;
}

int main() {
    vector<int> arr = {0, -8, -6, 3};
    cout << solve(arr) << endl;
    return 0;
}