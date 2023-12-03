#include <bits/stdc++.h>
using namespace std;
// for longest palindromic subsequence take the string s and t(reverse of s) and find LCS.
string LCS(string s,string t,int m,int n){
  vector<vector<int>>dp(m+1,vector<int>(n+1));
  for(int i=0;i<m+1;i++){
    dp[i][0] = 0;
  }
  for(int j=0;j<n+1;j++){
    dp[0][j] = 0;
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
  string ans;
  int i = m;
  int j = n;
  while(i>0 && j>0){
    if(s[i-1] == t[j-1]){
      ans.push_back(s[i-1]);
      i--;
      j--;
    }else{
      if(dp[i][j-1] >= dp[i-1][j]){
        j--;
      }else{
        i--;
      }
    }
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int main(){
  string s,t;
  cin>>s>>t;
  cout<<LCS(s,t,s.size(),t.size());
  return 0;
}