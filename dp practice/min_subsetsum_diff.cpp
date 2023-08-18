#include<bits/stdc++.h>
using namespace std;

bool issubset(vector<int>a,int n,double sum){
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
  int sum = accumulate(a.begin(),a.end(),0);
  int max_possible = INT_MIN;
  for(int i=0;i<=sum/2;i++){
    if(issubset(a,n,i)){
      max_possible = max(max_possible,i);
    }
  }
  cout<<sum - 2*max_possible; 
  return 0;
}