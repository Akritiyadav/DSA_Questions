#include <bits/stdc++.h>
using namespace std;

struct Triplet {
    int start, end, weight;
};

bool solve(vector<Triplet> edges, int v, int src) {
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (auto& e : edges) {
            if (dist[e.start] != INT_MAX &&
                dist[e.start] + e.weight < dist[e.end]) {
                dist[e.end] = dist[e.start] + e.weight;
            }
        }
    }

    
    for (auto& e : edges) {
        if (dist[e.start] != INT_MAX &&
            dist[e.start] + e.weight < dist[e.end]) {
            return true; 
        }
    }
    return false;
}

int main(){
     vector<Triplet> edges;
     edges.push_back({0, 1, 1});
    edges.push_back({1, 2, -1});
    edges.push_back({2, 0, -1});


    int V = 2, src = 0;

    bool hasNegativeCycle = solve(edges, V, src);

    if (hasNegativeCycle) {
        cout << "True";
    } else {
        cout << "False";
    }
}