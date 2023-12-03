#include <bits/stdc++.h>
using namespace std;

int main(){
  string s="abcdefghijklmnopqr";

  unordered_map<string,int> mp;

  for (int i =0;i<s.length();i=i+3){
    mp[s.substr(i,3)]++;
  }

  for (auto i:mp){
    cout<<i.first<<" "<<i.second<<endl;
  }
  return 0;
}
