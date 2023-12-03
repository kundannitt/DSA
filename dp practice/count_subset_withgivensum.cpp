#include<bits/stdc++.h>
using namespace std;

int issubset(vector<int>a,int n,double sum){
  if(sum == 0){
    return 1;
  }
  if(n==0){
    return 0;
  }
  if(a[n-1] <= sum){
    return issubset(a,n-1,sum-a[n-1]) + issubset(a,n-1,sum);
  }else
    return issubset(a,n-1,sum);
}

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(auto &i:a)cin>>i;
  int sum;
  cin>>sum;
  cout<<issubset(a,n,sum);
  return 0;
}