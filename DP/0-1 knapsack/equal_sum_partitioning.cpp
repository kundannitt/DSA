// we have to find a subset whose sum is total_sum/2, also the total_sum 
//must be even for such a possible thing.
#include <bits/stdc++.h>
using namespace std;

bool ifpossible(vector<int>arr,int n,int sum){
  vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
  for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
      if(i==0){
        dp[i][j] = false;
      }
      if(j==0){ //  sum is 0 => empty subset.
        dp[i][j] = true;
      }
    }
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
      if(arr[i-1] <=j){
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
  for(auto &i:arr) cin>>i;
  int sum = accumulate(arr.begin(),arr.end(),0);
  cout<<ifpossible(arr,n,sum/2);
  return 0;
}
