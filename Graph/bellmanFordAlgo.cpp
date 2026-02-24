#include <bits/stdc++.h>
using namespace std;

struct Triplet {
    int start, end, weight;
};

using ll = long long;

vector<ll> solve(vector<Triplet> edges, int v, int src) {
    vector<ll> dist(v, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            Triplet triplet = edges[j];
            if (dist[triplet.end] > dist[triplet.start] + triplet.weight) {
                dist[triplet.end] = dist[triplet.start] + triplet.weight;
            }
        }
    }
    return dist;
}

int main() {
    vector<Triplet> edges;
    edges.push_back({0, 1, 10});
    edges.push_back({0, 2, 3});
    edges.push_back({1, 3, 1});
    edges.push_back({2, 1, 1});
    edges.push_back({2, 3, 2});
    vector<ll> ans = solve(edges, 4, 0);
    for (auto i : ans) {
        cout << i << " ";
    }
}