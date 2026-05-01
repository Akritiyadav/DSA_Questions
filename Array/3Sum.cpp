#include<bits/stdc++.h>
using namespace std;

//Hash Set approach- O(n^2) Time and O(n) Space

bool solve(vector<int>&arr,int target){
    int n=arr.size();

    // Fix the first element as arr[i] 
    for (int i = 0; i < n - 2; i++) {
      
        // Hash set to store potential second elements
        unordered_set<int> st;
      
        // Fix the third element as arr[j]
        for(int j = i + 1; j < n; j++) {
            int second = target - arr[i] - arr[j];
          
            // Search for second element in hash set
        	if(st.find(second) != st.end()) {
            	return true;
            }
          
            // Add arr[j] as a potential second element
            st.insert(arr[j]);
        }
    } 
}


// [Expected Approach] - Sorting and Two Pointer - O(n^2) Time and O(1) Space

bool solve2(vector<int>&arr,int target){

    int n=arr.size();
   sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){

        int l=i+1,r=n-1;

        int reqSum=target-arr[i];
        while(l<r){
          if(arr[l]+arr[r]==reqSum){
            return true;
          }else if(arr[l]+arr[r]<reqSum){
            l++;
          }else{
            r--;
          }
        }
    }
    return false;
}

int main() { 
    vector<int> arr = { 1, 4, 45, 6, 10, 8}; 
    int target = 13; 
    if(solve2(arr, target))
        cout << "true";
    else
        cout << "false";
    return 0; 
}
