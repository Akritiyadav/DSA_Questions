#include<bits/stdc++.h>
using namespace std;

// recursive approach   tc:-(2)^n
int recur(vector<int>cost ,int ind){
    int n=cost.size();
    if(ind==0) return 0;
    if(ind==1) return 0;
    return min(recur(cost,ind-1)+cost[ind-1],recur(cost,ind-2)+cost[ind-2]);
}
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    return recur(cost,n);
}

// top down   tc:-O(n)
int memo(int ind,vector<int>cost,vector<int>&dp){
    if(ind==0) return 0;
    if(ind==1) return 0;
    if(dp[ind]!=-1) return dp[ind];

    dp[ind]=min(recur(cost,ind-1)+cost[ind-1],recur(cost,ind-2)+cost[ind-2]);
    return dp[ind];
}
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    return memo(n, cost, dp);
}

// bottom up    TC:-O(n)
int funBottomUp(vector<int>cost){
    int n=cost.size();
     int paid[n+1];
     paid[0]=0; 
     paid[1]=0;
     for(int i=2;i<=n;i++){
        paid[i]=min(paid[i-1]+cost[i-1],paid[i-2]+cost[i-2]);
     }
     return paid[n];

}
int main(){
    vector<int> cost = { 16, 19, 10, 12, 18 };
    cout << funBottomUp(cost) << endl;
	return 0;
}
