#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo(100,vector<int>(100,-1));

int LCS(string s,string t,int m,int n){
  if(memo[m][n] != -1){
    return memo[m][n];
  }
  if(m==0 || n==0){
    memo[m][n] = 0;
  }else{
    if(s[m-1] == t[n-1]){
      memo[m][n] =  1 + LCS(s,t,m-1,n-1);
    }else{
      memo[m][n] = max(LCS(s,t,m-1,n),LCS(s,t,m,n-1));
    }
  }
  return memo[m][n];
}

int main(){
  string s,t;
  cin>>s>>t;
  cout<<LCS(s,t,s.size(),t.size());
  return 0;
}