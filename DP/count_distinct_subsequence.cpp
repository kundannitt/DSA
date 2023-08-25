#include <bits/stdc++.h>
using namespace std;
static constexpr int MOD = 1e9 + 7;
int count(string s){
  int n = s.size();
  vector<long long>dp(n+1);
  vector<int>last(26,-1);
  dp[0] = 1;
  for(int i=1;i<=s.size();i++){
    dp[i] = 2 * dp[i-1];
    if(last[s[i-1]-'a'] != -1){
      dp[i] = 2 * dp[i-1] - dp[last[s[i-1]-'a']];
    }
    dp[i] %= MOD;
    last[s[i-1]-'a'] = i-1;
  }
  if(dp[n] <= 0){
    dp[n] += MOD;
  }
  return dp[n] - 1;
}

int main(){
  string s;
  cin>>s;
  cout<<count(s);
  return 0;
}