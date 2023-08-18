#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>wt,vector<int>val,int n, int w){
  if(n==0 || w==0){
    return 0;
  }
  else if(wt[n-1] <=w){
    return max(val[n-1]+knapsack(wt,val,n,w-wt[n-1]),knapsack(wt,val,n-1,w));
  }else if(wt[n-1]>w)
    return knapsack(wt,val,n-1,w);
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
  cout<<knapsack(wt,val,n,w);
  return 0;
}