#include <bits/stdc++.h>
using namespace std;
// for longest palindromic subsequence take the string s and t(reverse of s) and find LCS.
int LCS(string s,string t,int m,int n){
  vector<vector<int>>dp(m+1,vector<int>(n+1));
  for(int i=0;i<m+1;i++){
    dp[i][0] = 0;
  }
  for(int i=0;i<n+1;i++){
    dp[0][i] = 0;
  }
  for(int i=1;i<m+1;i++){
    for(int j=1;j<n+1;j++){
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
  cout<<LCS(s,t,s.size(),t.size());
  return 0;
}