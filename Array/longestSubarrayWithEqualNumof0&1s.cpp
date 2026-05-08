
#include<bits/stdc++.h>
using namespace std;

 int maxLen(vector<int>& arr) {

        unordered_map<int, int> mp;

        int prefixSum = 0;
        int maxLength = 0;

        // IMPORTANT:
        // sum 0 seen at index -1
        mp[0] = -1;

        for(int i = 0; i < arr.size(); i++) {

            
            // Convert:
            // 0 -> -1
            // 1 -> +1
            
            if(arr[i] == 0)
                prefixSum += -1;
            else
                prefixSum += 1;

           
            // If same prefix sum already seen,
            // subarray between them has sum 0
           
            if(mp.find(prefixSum) != mp.end()) {

                int len = i - mp[prefixSum];

                maxLength = max(maxLength, len);
            }

            // store first occurrence only
            else {
                mp[prefixSum] = i;
            }
        }

        return maxLength;
    }

    int main() {
    vector<int> arr = {1, 0, 0, 1, 0, 1, 1};
  
    cout << maxLen(arr) << endl;
    return 0;
}