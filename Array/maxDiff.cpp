#include<bits/stdc++.h>
using namespace std;

/* 
   Given an array of integers, the task is to find the maximum difference between any two elements such that larger element appears after the smaller number.  We mainly need to find maximum difference in an inversion (larger before smaller)

Note: If no such pair exists, return -1.
*/

int solve(vector<int>&arr){
    int n=arr.size();
    int mini=arr[0];
    int ans=-1;

    for(int i=1;i<n;i++){

        if(arr[i]<mini){
            mini=arr[i];
        }else{
            ans=max(ans,arr[i]-mini);
        }
    }
    return ans;
}


//optimal approach

/* arr = {2, 3, 10}
Difference array:

{1, 7}
Now:

arr[2] - arr[0] = 10 - 2 = 8
Same as:

1 + 7 = 8
🔥 So the problem becomes:
👉 Find a continuous segment in diff array
👉 whose sum is maximum

 */

  int maxDiff(vector<int>&arr){
    int n = arr.size();

	int diff = arr[1]-arr[0];
	int currSum = diff;
	int maxSum = -1;

	if (currSum>0) maxSum = currSum;

	for(int i=1; i<n-1; i++)
	{
		// Calculate current diff
		diff = arr[i+1]-arr[i];

		// Calculate current sum
		if (currSum > 0)
			currSum += diff;
		else
			currSum = diff;

		// Update max sum, if needed
		if (currSum >0 && currSum > maxSum)
			maxSum = currSum;
	}

	return maxSum;
     
  }

int main() {
	vector<int> arr = {2, 3, 10, 6, 4, 8, 1};
	cout << solve(arr);
	return 0;
}