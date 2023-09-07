#include<bits/stdc++.h>
using namespace std;

void printsub(string s,string &out){
  if(out.size() == 2){
    cout<<out<<" ";
    return;
  }
  if(s.empty()){
    return;
  }
  out.push_back(s[0]);
  printsub(s.substr(1),out);
  out.pop_back();
  printsub(s.substr(1),out);
}

int main(){
  string s;
  cin>>s;
  string out;
  printsub(s,out);
  return 0;
}