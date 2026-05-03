#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat) {

    int n = mat.size();
    int m = mat[0].size();

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    vector<int> ans;

    while (top <= bottom && left <= right) {

        // 1. Traverse top row
        for (int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        }
        top++;

        // 2. Traverse right column
        for (int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--;

        // 3. Traverse bottom row (only if valid)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // 4. Traverse left column (only if valid)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}


int main(){
       vector<vector<int>> mat = { { 1, 2, 3, 4 },
                                { 5, 6, 7, 8 },
                                { 9, 10, 11, 12 },
                                { 13, 14, 15, 16 } 
                              };

    vector<int> res = spirallyTraverse(mat);

    for (int num : res) {
        cout << num << " ";
    }
    return 0;
}