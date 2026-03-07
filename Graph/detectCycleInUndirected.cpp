#include<bits/stdc++.h>
using namespace std;

bool bfs(int src,vector<vector<int>>&graph,vector<bool>&vis){
    queue<pair<int,int>>q;
    q.push({src,-1});
    vis[src]=true;

    while(q.size()){
        auto front=q.front();
        q.pop();

        for(auto it:graph[front.first]){
            if(!vis[it]){
                vis[it]=true;
                q.push({it,front.first});
            }
            else if(front.second!=it){
                return true;
            }
        }
    }

    return false;
}

bool isCycle(vector<vector<int>>&graph){
     int V=graph.size();
    vector<bool>vis(V,false);

    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(bfs(i,graph,vis)) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> adj = {{1}, {0, 2}, {1, 3}, {2}};
    isCycle(adj) ? cout << "true" : cout << "false";

    return 0;
}