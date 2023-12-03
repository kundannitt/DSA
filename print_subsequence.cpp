#include<bits/stdc++.h>
using namespace std;

void printsub(string s,int i,string out){
  if(i == s.size()){
    // if(out.size() == 2){ for specific size.
    //   cout<<out<<endl;
    // }
    cout<<out<<" ";
    return;
  }
  // out.push_back(s[i]);
  printsub(s,i+1,out + s[i]);
  // out.pop_back();
  printsub(s,i+1,out);
  
}

int main(){
  string s;
  cin>>s;
  printsub(s,0,"");
  return 0;
}