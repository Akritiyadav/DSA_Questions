#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int>&arr){
    int n=arr.size();
    vector<int>res(n,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                res[i]*=arr[j];
            }
        }
    }
    return res;
}

//using prefix and suffix

vector<int> solve(vector<int>&arr){
    int n=arr.size();

    vector<int>suffix(n),prefix(n),res(n);

    prefix[0]=1;
    for(int i=1;i<n;i++){
        prefix[i]=arr[i-1]*prefix[i-1];
    }

    suffix[n-1]=1;
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*arr[i+1];
    }

    for(int i=0;i<n;i++){
        res[i]=prefix[i]*suffix[i];
    }
    return res;
}

int main() {
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = solve(arr);
    for (int val : res) 
        cout << val << " ";
    return 0;
}
