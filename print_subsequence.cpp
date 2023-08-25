#include<bits/stdc++.h>
using namespace std;

void printsub(string s,string out){
  if(s.empty()){
    cout<<out<<endl;
    return;
  }
  printsub(s.substr(1),out+s[0]);
  printsub(s.substr(1),out);
}

int main(){
  string s;
  cin>>s;
  printsub(s,"");
  return 0;
}