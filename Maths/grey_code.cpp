#include <bits/stdc++.h>
using namespace std;

string binary(int n){
  string ans;
  if(n == 0){
    return "0000";
  }
  while(n > 0){
    ans.push_back((n&1) + '0');
    n = n >> 1;
  }
  while(ans.size() != 4){
    ans.push_back('0');
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<pow(2,n);i++){
    string bin = binary(i);
    string grey;
    grey.push_back(bin[0]);
    for(int i=1;i<bin.size();i++){
      grey.push_back((bin[i] - '0') ^ (bin[i-1] - '0') + '0');
    }
    cout<<bin<<" ";
    cout<<grey<<endl;
  }
  return 0;
}