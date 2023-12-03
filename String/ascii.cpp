// to convert a number inside a string to int => s[i]-'0;
// to convert number to alphabets(a,b,c...z) => (char)s[i]+'a';

#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.length();i++){
    cout<<s[i]-'0';
    int x=(s[i]-'0')-1;
    cout<<char(x+'a')<<endl;
  }
}