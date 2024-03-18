#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  char c;
  cin>>s;
  cin>>c;
  int x = count(s.begin(),s.end(),c);
  cout<<x;
  return 0;
}