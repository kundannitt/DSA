#include <bits/stdc++.h>
using namespace std;

void move0(vector<int>&a){
  int index = 0;
  for(int i=0;i<a.size();i++){
    if(a[i]!=0){
      swap(a[i],a[index]);
      index++;
    }
  }
}

void print(vector<int>a){
  for(auto i:a) cout<<i<<" ";
}

int main(){
  int n;
  cin>>n;
  vector<int>b(n);
  for(auto &i:b) cin>>i;
  move0(b);
  print(b);
  return 0;
}