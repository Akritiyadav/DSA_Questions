#include<bits/stdc++.h>
using namespace std;

vector<int> interSection(vector<int>&a,vector<int>&b){
    int n=a.size(),m=b.size();
    int i=0,j=0;
    vector<int>ans;
    while(i<n and j<m){
        if(i>0 and a[i-1]==a[i]){
            i++;
            continue;
        }

        if(a[i]<b[j]){
            i++;
        }else if(b[j]<a[i]){
            j++;
        }else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {1, 1, 2, 2, 2, 4};
    vector<int> b = {2, 2, 4, 4};
    vector<int> res = interSection(a, b);
    for (int x : res) {
        cout << x << " ";
    }
}