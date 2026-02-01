#include <bits/stdc++.h>
using namespace std;

//insertion sort method
int solve(vector<int>& arr) {
    vector<int> a;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (a.empty() or a.back() < arr[i]) {
            a.push_back(arr[i]);
            ans = max(ans, (int)a.size());
            continue;
        }
        int start = 0, end = a.size()-1,idx=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(a[mid]<arr[i]){
                start=mid+1;
            }else{
                idx=mid;
                end=mid-1;
            }
        }
        a[idx]=arr[i];
    }
    return ans;
}
int lISDP(vector<int>& arr) {
    int n = arr.size();
    int dp[n];
    fill_n(&dp[0], n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    int ans = 0;
    for (int i : dp) {
        ans = max(ans, i);
    }
    return ans;
}
int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout <<solve(arr);
    return 0;
}