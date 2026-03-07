#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<bool>>&graph, int start, int curr, int len, int n,int &cnt, vector<bool>&vis){
    vis[curr]=true;
    if(len==n and graph[start][curr]){
        cnt++;
    } else if(len==n){
        return;
    }

    for(int i=0;i<graph.size();i++){
        if(graph[curr][i] and vis[i]==false){
            dfs(graph,start,i,len+1,n,cnt,vis);
        }
    }
    vis[curr]=false;
}

int countCycles(vector<vector<bool>>&graph,int n){
   int cnt=0,v=graph.size();
   vector<bool>vis(v,false);
   for(int i=0;i<v;i++){
    dfs(graph,i,i,1,n,cnt,vis);
    vis[i]=true;
   }
   return cnt/2;
}



int main() {
   int V = 5;
   vector<vector<bool>>graph = {{0, 1, 0, 1, 0},
                {1, 0, 1, 0, 1},
                {0, 1, 0, 1, 0},
                {1, 0, 1, 0, 1},
                {0, 1, 0, 1, 0}};
   int n = 4;
   cout << "Total cycles of length " << n << " are "
        << countCycles(graph, n);
   return 0;
}

