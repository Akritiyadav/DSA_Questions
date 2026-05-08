#include <bits/stdc++.h>
using namespace std;

// Function to find all leader elements in the array
//
// A leader is an element which is greater than or equal to
// all elements present on its right side.
//
// Example:
// arr = [16, 17, 4, 3, 5, 2]
//
// Leaders = [17, 5, 2]

vector<int> leaders(vector<int>& arr) {

    vector<int> res;

    int n = arr.size();

    // Rightmost element is always a leader
    // because there are no elements on its right
    int maxRight = arr[n - 1];

    res.push_back(maxRight);

    // Traverse array from right to left
    for(int i = n - 2; i >= 0; i--) {

        // If current element is greater than or equal to
        // maximum element seen so far on right side,
        // then it is a leader
        if(arr[i] >= maxRight) {

            // Update maximum element on right side
            maxRight = arr[i];

            // Store leader
            res.push_back(arr[i]);
        }
    }

    // Leaders are collected in reverse order
    // because traversal happened from right to left
    reverse(res.begin(), res.end());

    return res;
}

int main() {

    vector<int> arr = {16, 17, 4, 3, 5, 2};

    vector<int> res = leaders(arr);

    // Print all leaders
    for(int x : res) {
        cout << x << " ";
    }

    return 0;
}