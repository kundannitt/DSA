// return max profit(take max value) when size of bag is W.
// visited values can be taken again.
#include <bits/stdc++.h>
using namespace std;

//DP
int knapsack(vector<int>wt,vector<int>val,int n,int W){
  vector<vector<int>>dp(n+1,vector<int>(W+1));
  for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
      if(i==0 || j==0){
        dp[i][j] = 0;
      }
    }
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<W+1;j++){
      if(wt[i-1] <= j){
        dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]] ,dp[i-1][j]); // when we include the val[i-1], we don't decrease value of n.
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][W];
}

/*
recursive solution:-
int knapsack(vector<int>wt,vector<int>val,int n,int W){
  if(n==0 || W==0){
    return 0;
  }
  if(wt[n-1] <= W){
    return max(val[n-1] + knapsack(wt,val,n,W-wt[n-1]) , knapsack(wt,val,n-1,W));
  }else{
    return knapsack(wt,val,n-1,W);
  }
}
*/

int main(){
  int n;
  cin>>n;
  vector<int>wt(n);
  vector<int>val (n);
  for(auto &i:wt) cin>>i;
  for(auto &i:val) cin>>i;
  int W;
  cin>>W;
  cout<<knapsack(wt,val,n,W);
  return 0;
}