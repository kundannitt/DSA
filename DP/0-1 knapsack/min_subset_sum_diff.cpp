#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>arr,int n,int sum){
  vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
  for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
      if(i==0){
        dp[i][j] = false;
      }
      if(j==0){
        dp[i][j] = true; // empty subset.
      }
    }
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
      if(arr[i-1] <= j){
        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
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
  vector<int>arr(n);
  for(auto &i:arr)cin>>i;
  vector<int>possiblesum;
  int total_sum = accumulate(arr.begin(),arr.end(),0);
  for(int i=0;i<=total_sum/2;i++){
    if(possible(arr,n,i)){
      possiblesum.push_back(i);
    }
  }
  int ans = INT_MAX;
  for(int i=0;i<possiblesum.size();i++){
    ans = min(ans ,total_sum - 2*possiblesum[i]);
  }
  cout<<ans;
  return 0;
}