#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>memo;
bool issubset(vector<int>a,int n,int sum){
  if(sum == 0){
    return true;
  }
  if(n==0){
    return false;
  }
  if(memo[n][sum] != -1){
    return memo[n][sum];
  }
  if(a[n-1] <= sum){
    return memo[n][sum] = issubset(a,n-1,sum-a[n-1]) || issubset(a,n-1,sum);
  }else
    return memo[n][sum] = issubset(a,n-1,sum);
}

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(auto &i:a)cin>>i;
  int sum;
  cin>>sum;
  memo = vector<vector<int>>(n+1,vector<int>(sum+1,-1));
  cout<<issubset(a,n,sum);
  return 0;
}