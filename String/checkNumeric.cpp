// using find_first_not_of() function
#include <bits/stdc++.h>
using namespace std;

bool solve(string s){
  return s.find_first_not_of("0123456789") == string::npos;
}

int main(){
  cout<<solve("124354")<<endl;
  cout<<solve("13222b444")<<endl;
  cout<<solve("dsd")<<endl;
  return 0;
}