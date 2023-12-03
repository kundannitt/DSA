#include <bits/stdc++.h>
using namespace std;
int LCS(string s,string t,int m,int n){
  vector<vector<int>>dp(m+1,vector<int>(n+1));
  for(int i=0;i<m+1;i++){
    dp[i][0] = 0;
  }
  for(int i=0;i<n+1;i++){
    dp[0][i] = 0;
  }
  int ans = 0;
  for(int i=1;i<m+1;i++){
    for(int j=1;j<n+1;j++){
      if(s[i-1] == t[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
        ans = max(ans,dp[i][j]);
      }else{
        dp[i][j] = 0;
      }
    }
  }
  return ans;
}

int main(){
  string s,t;
  cin>>s>>t;
  cout<<LCS(s,t,s.size(),t.size());
  return 0;
}