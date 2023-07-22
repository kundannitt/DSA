#include <bits/stdc++.h>
using namespace std;
//using tabulation
int lcs(string s,string t,int m,int n){
  vector<vector<int>>dp(m+1,vector<int>(n+1));
  for(int i=0;i<m;i++){
    dp[i][0] = 0;
  }
  for(int i=0;i<n;i++){
    dp[0][i] = 0;
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(s[i-1] == t[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
      }else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  return dp[m][n];
}

int main(){
  string s,t;
  cin>>s>>t;
  cout<<lcs(s,t,s.size(),t.size());
  return 0;
}