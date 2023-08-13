// return a string of shortest length having both str1 and str2 as subsequence.
//idea:- char in LCS(str1,str2) will ocuur only once in ans.
#include<bits/stdc++.h>
using namespace std;
string shortestCommonSupersequence(string str1, string str2) {
  int m = str1.size();
  int n = str2.size();
  //LCS-----------------------------------------------
  vector<vector<int>>dp(m+1,vector<int>(n+1));
  for(int i=0;i<=m;i++){
    dp[i][0] = 0;
  }
  for(int j=0;j<=n;j++){
    dp[0][j] = 0;
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(str1[i-1] == str2[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
      }else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  //-----------------------------------------------------
  string ans = "";
  int i = m,j=n;
  while(i>0 && j>0){
    if(str1[i-1] == str2[j-1]){
      ans.push_back(str1[i-1]);
      i--;
      j--;
    }else{ // if doesn't match print the curr char and move towards the larger value as in LCS.
      if(dp[i][j-1] > dp[i-1][j]){
        ans.push_back(str2[j-1]);
        j--;
      }else{
        ans.push_back(str1[i-1]);
        i--;
      }
    }
  }
  while(i>0){
    ans.push_back(str1[i-1]);
    i--;
  }
  while(j>0){
    ans.push_back(str2[j-1]);
    j--;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
int main(){
  string str1,str2;
  cin>>str1>>str2;
  cout<<shortestCommonSupersequence(str1,str2);
  return 0;
}