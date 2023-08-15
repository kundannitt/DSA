#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
bool solve(string s,string t){
  if(s==t){
    return true;
  }
  if(s.size() <= 1){
    return false;
  }
  string temp = s;
  temp.push_back(' ');
  temp += t;
  if(mp.find(temp) != mp.end()){
    return mp[temp];
  }
  int n = s.size();
  bool ans = false;
  for(int i=1;i<n;i++){
    bool con1 = solve(s.substr(0,i),t.substr(n-i,i)) 
              && solve(s.substr(i,n-i),t.substr(0,n-i));
    bool con2 = solve(s.substr(0,i),t.substr(0,i)) 
              && solve(s.substr(i,n-i),t.substr(i,n-i));
    if(con1 || con2 == true){
      ans = true;
      break;
    }
  }
  return mp[temp] = ans;
}
bool isScramble(string s1, string s2) {
  if(s1==s2){
    return true;
  }
  if(s1.empty() && s2.empty()){
    return true;
  }
  if(s1.size() != s2.size()){
    return false;
  }
  return solve(s1,s2);
}
int main(){
  string s,t;
  cin>>s>>t;
  cout<<isScramble(s,t);
  return 0;
}