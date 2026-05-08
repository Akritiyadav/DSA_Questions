#include<bits/stdc++.h>
using namespace std;


  vector<int> subarraySum(vector<int> &arr, int target) {
        
        int n = arr.size();

        int left = 0;
        int currSum = 0;

        // right pointer expands window
        for(int right = 0; right < n; right++) {

            // add current element into window
            currSum += arr[right];

            
            // If sum becomes greater than target,
            // shrink window from left
            
            
            while(currSum > target && left <= right) {
                
                currSum -= arr[left];
                left++;
            }

            
            // If target found
            // return 1-based indexing
            
            if(currSum == target) {
                return {left + 1, right + 1};
            }
        }

        // no subarray found
        return {-1};
    }


    int main() {
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;
    vector<int> res = subarraySum(arr, target);
  
    for (int ele : res)
        cout << ele << " ";
    return 0;
}