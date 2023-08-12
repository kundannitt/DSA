// min  no. of coins
#include <bits/stdc++.h>
using namespace std;

int totalCombination(vector<int>coins,int sum){
  int n = coins.size();
  vector<vector<int>>dp(n+1,vector<int>(sum+1));
  //in this unique problem we initialise 2nd row also.
  for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
      if(i==0){ // no coins
        dp[i][j] = 0;
      }
      if(j==0){ // sum 0 => empty set. since asked all ways.
        dp[i][j] = 1;
      }
    }
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
      if(coins[i-1] <=j){
        dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][sum];
}

int main(){
  int n;
  cin>>n;
  vector<int>coins(n+1);
  for(auto &i:coins)cin>>i;
  int sum ;
  cin>>sum;
  cout<<totalCombination(coins,sum);
  return 0;
}