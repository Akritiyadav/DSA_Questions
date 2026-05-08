#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums){
    int currMax = nums[0];
    int currMin = nums[0];
    int ans = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        
        int tempMax = currMax;   // store previous max
        int tempMin = currMin;   // store previous min

        // compute using all possibilities
        currMax = max({nums[i], nums[i] * tempMax, nums[i] * tempMin});
        currMin = min({nums[i], nums[i] * tempMax, nums[i] * tempMin});

        ans = max(ans, currMax);
    }
    return ans;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << solve(arr);
    return 0;
}