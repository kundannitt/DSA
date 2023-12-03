#include <bits/stdc++.h>
using namespace std;

int LCS(string s,string t,int m,int n){
  if(n==0 || m==0){
    return 0;
  }
  if(s[m-1] == t[n-1]){
    return 1 + LCS(s,t,m-1,n-1);
  }else{
    return max(LCS(s,t,m-1,n),LCS(s,t,m,n-1));
  }
}

int main(){
  string s,t;
  cin>>s>>t;
  cout<<LCS(s,t,s.size(),t.size());
  return 0;
}