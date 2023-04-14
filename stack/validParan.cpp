#include <bits/stdc++.h>
using namespace std;
bool match(char a,char b){
  return (a=='(' && b==')') || (a=='[' || b==']') || (a=='{' || b=='}');
}
bool checkValid(string s){
  stack <char> st;

  for(auto i:s){
    if(i=='(' || i=='{' || i=='['){
      st.push(i);
    }else{
      if(st.empty()==true){
        return false;
      }
      if(match(st.top(),i)==false){
        return false;
      }else{
        st.pop();
      }
    }
  }
  return (st.empty()==true);
}

int main(){
  string s;
  cin>>s;
  cout<<checkValid(s);
  return 0;
}