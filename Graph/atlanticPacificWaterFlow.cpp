#include<bits/stdc++.h>
using namespace std;

bool safe(int x, int y, int X, int Y){
    return x>=0 and y>=0 and x<X and y<Y;
}

void bfs(vector<vector<int>>&mat,queue<pair<int,int>>&q,vector<vector<bool>>&vis){
    int n=mat.size();
    int m=mat[0].size();
     int X[]={-1,1,0,0};
     int Y[]={0,0,-1,1};
     while(q.size()){
        auto front=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int x=front.first+X[i];
            int y=front.second+Y[i];
            if(safe(x,y,n,m) and mat[x][y]>=mat[front.first][front.second] and vis[x][y]==false){
                vis[x][y]=true;
                q.push({x,y});
            }
        }
     }
}

int solve(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();

    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

     queue<pair<int,int>>q1,q2;

     for(int i=0;i<m;i++){
        pacific[0][i]=true;
        q1.push({0,i});
     }
     for(int i=0;i<n;i++){
        pacific[i][0]=true;
        q1.push({i,0});
     }


     for(int i=0;i<m;i++){
        atlantic[n-1][i]=true;
        q2.push({n-1,i});
     }
     for(int i=0;i<n;i++){
        atlantic[i][m-1]=true;
        q2.push({i,m-1});
     }

     bfs(mat,q1,pacific);
     bfs(mat,q2,atlantic);

     int ans=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pacific[i][j] and atlantic[i][j]){
                ans++;
            }
        }
     }
     return ans;
}

int main()
{
    vector<vector<int> > mat
        = { { 2,2 },
            { 2,2 }, };

    cout << solve(mat);
    return 0;
}