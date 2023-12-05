#include <bits/stdc++.h>
using namespace std;
int main(){
  string s = "10001011101011001";
  //format : stoi(string_name,nullptr,base);
  long long num = stoi(s,nullptr,2);
  cout<<num;
  return 0;
}