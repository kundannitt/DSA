#include <bits/stdc++.h>
using namespace std;
//return length of the longest repeating subsequence.
int LRS(string s){
  string t = s;
  //find LCS of both under condition that i!=j
  int n = s.size();
  vector<vector<int>>dp(n+1,vector<int>(n+1,0));
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){
      if(s[i-1] == t[j-1] && i!=j){
        dp[i][j] = 1 + dp[i-1][j-1];
      }else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  return dp[n][n];
}

int main(){
  string s;
  cin>>s;
  cout<<LRS(s);
  return 0;
}
/*
  S: AABEBCDD
  o/p :- 3 (ABE) used characters can not be used.
*/