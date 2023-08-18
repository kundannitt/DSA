#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>memo;
int knapsack(vector<int>wt,vector<int>val,int n, int w){
  if(n==0 || w==0){
    return 0;
  }
  if(memo[n][w] != -1){
    return memo[n][w];
  }
  else if(wt[n-1] <=w){
    return memo[n][w] = max(val[n-1]+knapsack(wt,val,n-1,w-wt[n-1]),knapsack(wt,val,n-1,w));
  }else if(wt[n-1]>w)
    return memo[n][w] = knapsack(wt,val,n-1,w);
}

int main(){
  int n;
  cin>>n;
  vector<int>wt(n);
  for(auto &i:wt)cin>>i;
  vector<int>val(n);
  for(auto &i:val)cin>>i;
  int w;
  cin>>w;
  memo = vector<vector<int>>(n+1,vector<int>(w+1,-1));
  cout<<knapsack(wt,val,n,w);
  return 0;
}