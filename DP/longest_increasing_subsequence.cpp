#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>a){
  vector<int>dp(a.size());
  dp[0] = 1;

  for(int i=1;i<a.size();i++){
    int x = INT_MIN; // for each ith element we go from i-1 to 0 and search for any element smaller than ith element and take their max lis value.
    for(int j=i-1;j>=0;j--){
      if(a[j] <= a[i]){
        x = max(x,dp[j]);
      }
    }
    if(x==INT_MIN){
      dp[i] = 1;
    }else{
      dp[i] = x + 1;
    }
  }
  for(int i:dp){
    cout<<i<<" ";
  }
  cout<<endl;
  return *max_element(dp.begin(),dp.end());
}

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(auto &i:a) cin>>i;
  cout<<lis(a);
  return 0;
}