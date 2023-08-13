// cut rod in any part possible and take their price (maximize it).
// exact same as unbounded knapsack.
#include <bits/stdc++.h>
using namespace std;

//DP
int knapsack(vector<int>len,vector<int>price,int n,int length){
  vector<vector<int>>dp(n+1,vector<int>(length+1));
  for(int i=0;i<n+1;i++){
    for(int j=0;j<length+1;j++){
      if(i==0 || j==0){
        dp[i][j] = 0;
      }
    }
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<length+1;j++){
      if(len[i-1] <= j){
        dp[i][j] = max(price[i-1] + dp[i][j-len[i-1]] ,dp[i-1][j]);
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][length];
}

/*
recursive solution:-
int knapsack(vector<int>lent,vector<int>price,int n,int length){
  if(n==0 || length==0){
    return 0;
  }
  if(lengtht[n-1] <= length){
    return max(price[n-1] + knapsack(len,price,n,length-len[n-1]) , knapsack(len,price,n-1,length));
  }else{
    return knapsack(lent,price,n-1,length);
  }
}
*/

int main(){
  int n;
  cin>>n;
  vector<int>len(n);
  for(int i=0;i<n;i++){
    len[i] = i+1;
  }
  vector<int>price (n);
  for(auto &i:price) cin>>i;
  int length;
  cin>>length;
  cout<<knapsack(len,price,n,length);
  return 0;
}