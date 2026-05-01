#include<bits/stdc++.h>
using namespace std;

//  Given a binary 2D array, where each row is sorted. Find the row with the maximum number of 1s. 

int solve(vector<vector<bool>>&arr){
    int n=arr.size();
    int maxRow=-1;
    int m=arr[0].size();
    int col=m-1;
    int row=0;

    while(row<n and col>=0){
        if(arr[row][col]==0){
            row+=1;
        }else{
          maxRow=row;
          col=col-1;
        }
    }
    return maxRow;
}

int main() {
    vector<vector<bool>> arr = { { 0, 0, 0, 1 },
                                 { 0, 1, 1, 1 },
                                 { 1, 1, 1, 1 },
                                 { 0, 0, 0, 0 } };

    cout << "Index of row with maximum 1s is "
         << solve(arr);

    return 0;
}