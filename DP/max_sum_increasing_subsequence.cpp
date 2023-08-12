// variation of longest increasing subsequence.
#include<bits/stdc++.h>
using namespace std;

int msis(vector<int>a){
  vector<int>dp(a.size());
  for(int i=0;i<a.size();i++){
    dp[i] = a[i];
    for(int j=0;j<i;j++){
      if(a[j] < a[i]){
        dp[i] = max(dp[i],dp[j]+a[i]);
      }
    }
  }
  return *max_element(dp.begin(),dp.end());
}

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(auto &i:a) cin>>i;
  cout<<msis(a);
  return 0;
}