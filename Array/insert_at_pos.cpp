#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int>v = {12,4,567,3,6,2,7,36};
  v.insert(v.begin()+2,90);
  for(auto i:v){
    cout<<i<<" ";
  }
  return 0;
}