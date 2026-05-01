// C++ program to find union of two sorted arrays using 
// merge step of merge sort

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int>& a,  vector<int>& b) {
    vector<int> res; 
    int n = a.size();
    int m = b.size();
  
    // This is similar to merge of merge sort
    int i = 0, j = 0;    
    while(i < n && j < m) {
      
        // Skip duplicate elements in the first array
        if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      
      	// Skip duplicate elements in the second array
      	if(j > 0 && b[j - 1] == b[j]) {
          	j++;
          	continue;
        }
      	
      	// select and add the smaller element and move
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
      	
      	// Skip duplicate elements in the first array
      	if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      	res.push_back(a[i]);
      	i++;
    }
  
  	// Add the remaining elements of b[]
  	while (j < m) {
      
      	// Skip duplicate elements in the second array
      	if(j > 0 && b[j - 1] == b[j]) {
            j++;
            continue;
        }
      	res.push_back(b[j]);
      	j++;
    }
    return res; 
}

int main() {
  
    vector<int> a = {1, 1, 2, 2, 2, 4};
    vector<int> b = {2, 2, 4, 4};
  
    vector<int> res = findUnion(a, b);
    for (int x : res) {
        cout << x << " ";
    }
}