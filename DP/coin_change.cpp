#include<bits/stdc++.h>
using namespace std;
/*
// recursive solution
int coinchange(vector<int>coins,int n,int sum){
  if(sum == 0){ // when sum is zero there is a way to make sum 0 that is take 0 coins.
    return 1;
  }
  if(n==0){ // since n is 0 and sum is not 0 here then there is no possible way to take coins.
    return 0;
  }
  int res = coinchange(coins,n-1,sum);
  if(coins[n-1] <= sum){
    res = res + coinchange(coins,n,sum - coins[n-1]);
  }
  return res;
}
*/

//dp
int coinchange(vector<int>coins,int n,int sum){
  vector<vector<int>>dp(sum+1,vector<int>(n+1));
  for(int i=0;i<=sum;i++){
    dp[i][0] = 0;
  }
  for(int j=0;j<=n;j++){
    dp[0][j] = 1;
  }
  for(int i=1;i<=sum;i++){
    for(int j=1;j<=n;j++){
      dp[i][j] = dp[i][j-1];
      if(coins[j-1] <= i){
        dp[i][j] += dp[i-coins[j-1]][j];
      }
    }
  }
  return dp[sum][n];
}

int main(){
  int n;
  cin>>n;
  vector<int>coins(n);
  for(auto &i:coins) cin>>i;
  int sum;
  cin>>sum;
  cout<<coinchange(coins,n,sum);
  return 0;
}