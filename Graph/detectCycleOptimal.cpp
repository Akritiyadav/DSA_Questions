#include<bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;


bool cycle(vvi graph, vector<bool>& visited , vector<bool>& processed, int src) {
   processed[src] = true;
   if (visited[src]) return true;
   visited[src] = true;
   for (int i = 0; i < graph[src].size(); i++) {
       if (cycle(graph, visited , processed, graph[src][i])) {
           return true;
       }
   }
   visited[src] = false;
   return false;
}


bool isCyclic(vvi graph) {
   int n = graph.size();
   vector<bool> visited(n);
   vector<bool> processed(n, false);
   for (int i = 0; i < n; i++) {
       if (processed[i] == false and  cycle(graph, visited , processed, i)) {
           return true;
       }
   }
   return false;
}


int main() {
   vector<vector<int>> adj = {{1}, {2}, {0, 3}};
   cout << (isCyclic(adj) ? "true" : "false") << endl;
}
