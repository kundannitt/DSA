#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int helper(string &s,string &t,int k,int i,int j){
  if(i <= 0 || j <= 0){
    return 0;
  }
  if(dp[i][j] != -1){
    return dp[i][j];
  }
  int x = s[i-1] - 'a';
  int y = t[j-1] - 'a';
  if((x-y+26)%26 <= k || (y-x+26)%26 <= k){
    return dp[i][j] = 1 + helper(s,t,k,i-1,j-1);
  }else{
    return dp[i][j] = max(helper(s,t,k,i-1,j) , helper(s,t,k,i,j-1));
  }
}

int solve(string &s,string &t,int k){
  dp.resize(s.size()+1,vector<int>(t.size()+1,-1));
  return helper(s,t,k,s.size(),t.size());
}

int main(){
  string s,t;
  cin>>s>>t;
  int k;
  cin>>k;
  cout<<solve(s,t,k);
  return 0;
}