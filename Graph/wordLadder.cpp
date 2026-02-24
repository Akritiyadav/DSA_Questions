#include <bits/stdc++.h>
using namespace std;

bool diffOne(string& a, string& b) {
    if (a.size() != b.size()) return false;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) cnt++;
    }
    return cnt == 1;
}

int solve(string& start, string& end, vector<string>& arr) {
    queue<pair<string, int>> q;
    q.push({start, 0});
    set<string> st;
    st.insert(start);
    while (q.size()) {
        auto front = q.front();
        q.pop();
        if (front.first == end) {
            return front.second;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (diffOne(front.first, arr[i]) && st.count(arr[i]) == 0) {
                q.push({arr[i], front.second + 1});
                st.insert(arr[i]);
            }
        }
    }
    return -1;
}

int main(){
     vector<string> arr = {"poon", "plee", "same", 
                          "poie", "plie", "poin", "plea"};
    string start = "toon";
    string target = "plea";

    cout << solve(start, target, arr) << endl;

    return 0;
}