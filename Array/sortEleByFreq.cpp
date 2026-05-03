#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int>& arr) {

    // Step 1: Count frequency
    unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }

    // Step 2: Sort with custom comparator
    sort(arr.begin(), arr.end(), [&](int a, int b) {

        // If frequency different
        if (freq[a] != freq[b]) {
            return freq[a] > freq[b];   // higher freq first
        }

        // If frequency same
        return a < b;  // smaller number first
    });

    return arr;
}





vector<int> sortByFreq(vector<int>& arr) {

    // Step 1: Count frequency
    unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }

    // Step 2: Create max heap
    // pair: {frequency, value}
    priority_queue<pair<int, int>> pq;

    // Push all elements into heap
    for (auto it : freq) {
        int num = it.first;
        int f = it.second;

        // push as {frequency, -value}
        // because for same freq → smaller number should come first
        pq.push({f, -num});
    }

    vector<int> ans;

    // Step 3: Build result
    while (!pq.empty()) {

        int f = pq.top().first;
        int num = -pq.top().second;  // convert back
        pq.pop();

        // add element f times
        for (int i = 0; i < f; i++) {
            ans.push_back(num);
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {5, 5, 4, 6, 4};

    vector<int> res = sortByFreq(arr);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}

