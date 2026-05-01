#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int>&a,vector<int>&b){
     vector<int> res; 
    int n = a.size();
    int m = b.size();
  
    // This is similar to merge of merge sort
    int i = 0, j = 0;    
    while(i < n && j < m) {
      
        if(a[i] < b[j]) {
          	res.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j]) {
          	res.push_back(b[j]);
            j++;
        }
      
        // If equal, then add to result and move both 
        else {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
  	
  	// Add the remaining elements of a[]
  	while (i < n) {
      	
      	res.push_back(a[i]);
      	i++;
    }
  
  	// Add the remaining elements of b[]
  	while (j < m) {
      	res.push_back(b[j]);
      	j++;
    }
    return res; 
}

int main() {
  
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 5, 7};
  
    vector<int> res = findUnion(a, b);
    for (int x : res) {
        cout << x << " ";
    }
}