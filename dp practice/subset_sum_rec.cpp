#include<bits/stdc++.h>
using namespace std;

bool issubset(vector<int>a,int n,int sum){
  if(sum == 0){
    return true;
  }
  if(n==0){
    return false;
  }
  if(a[n-1] <= sum){
    return issubset(a,n-1,sum-a[n-1]) || issubset(a,n-1,sum);
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