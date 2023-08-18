#include<bits/stdc++.h>
using namespace std;

int uknapsack(vector<int>len,vector<int>val,int n,int w){
  if(n==0 || w==0){
    return 0;
  }
  else if(len[n-1] <=w){
    return max(val[n-1]+uknapsack(len,val,n,w-len[n-1]),uknapsack(len,val,n-1,w));
  }else if(len[n-1]>w)
    return uknapsack(len,val,n-1,w);
}

int main(){
  int n;
  cin>>n;
  vector<int>len(n);
  for(int i=0;i<n;i++){
    len[i] = i + 1;
  }
  vector<int>val(n);
  for(auto &i:val)cin>>i;
  cout<<uknapsack(len,val,n,n);
  return 0;
}