#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findOddNumbers(vector<int>& arr) {
    int xorAll = 0;

    // Step 1: XOR all elements
    for (int num : arr) {
        xorAll ^= num;
    }

    // Step 2: Find rightmost set bit
    int setBit = xorAll & (-xorAll);

    int num1 = 0, num2 = 0;

    // Step 3: Divide into two groups
    for (int num : arr) {
        if (num & setBit)
            num1 ^= num;
        else
            num2 ^= num;
    }

    return {num1, num2};
}

int main() {
    vector<int> arr = {12, 23, 34, 12, 12, 23, 12, 45};

    pair<int, int> result = findOddNumbers(arr);

    cout << result.first << " " << result.second << endl;
}