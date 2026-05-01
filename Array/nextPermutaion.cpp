#include <bits/stdc++.h>
using namespace std;

void nextPermutaion(vector<int>& arr) {
    int n = arr.size();
    int ind = -1;
   for (int i = n - 1; i > 0; i--) {
    if (arr[i - 1] < arr[i]) {
        ind = i - 1;
        break;
    }
}

    if (ind == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    for (int i = n - 1; i > ind; i--) {
        if (arr[i] > arr[ind]) {
            swap(arr[ind], arr[i]);
            break;
        }
    }

    reverse(arr.begin() + ind + 1, arr.end());
}

int main(){
     vector<int> arr = {2, 4, 1, 7, 5, 0};

    nextPermutaion(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}