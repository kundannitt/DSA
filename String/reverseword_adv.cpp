#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
  string ans;

  //remove unnecessary spaces--------------------------------// 
  for(int i=0;i<s.length();i++){
    if(isalpha(s[i]) || isdigit(s[i])){
      ans.push_back(s[i]);
    }
    if(s[i]==' ' && i!=0 && s[i-1]!=' '){ 
      ans.push_back(s[i]);
    }
  }

  while(ans.back()==' '){
    ans.pop_back();
  }
  //-----------------------------------------------//
  reverse(ans.begin(),ans.end()); // then reverse whole string
//---------------------------reverse each word---------------------//
  int start=0;
  int n=ans.length();
  int count=0;
  
  for(int i=0;i<n;i++){
    if(ans[i]==' '){
      reverse(ans.begin()+start,ans.end()-n+count);
      start=i+1;
    }
    count++;
  }

  //-------------------------------------------------------------------//
  reverse(ans.begin()+start,ans.end());// reverse last word//
  return ans;
}

int main(){
  string s;
  getline(cin,s);
  cout<<reverseWords(s);
  return 0;
}