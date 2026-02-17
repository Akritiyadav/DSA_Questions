#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>graph,int src, vector<bool>&vis){
    if(vis[src]) return;
    vis[src]=true;
    cout<<src<<" ";
    for(auto child:graph[src]){
        dfs(graph,child,vis);
    }
}

int main(){
    vector<vector<int>> graph(5);

    graph[0] = {1, 2};
    graph[1] = {0, 2};
    graph[2] = {0, 1, 3, 4};
    graph[3] = {2};
    graph[4] = {2};
     vector<bool>vis(5,false);
    dfs(graph,0,vis);
}