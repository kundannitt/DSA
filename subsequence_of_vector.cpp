#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;

void generate(vector<int>&arr,int i,vector<int>out,int size,int n){
  if(out.size() == size){
    ans.push_back(out);
    out.pop_back();
  }
  if(i >= n){
    return;
  }
  out.push_back(arr[i]);
  generate(arr,i+1,out,size,n);
  out.pop_back();
  generate(arr,i+1,out,size,n);
}

void subsequence(vector<int>&arr,int size,int n){
  generate(arr,0,{},size,n);// for space optimization take a temp vector and pass as address.
}

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(auto &i : a) cin>>i;
  int size;
  cin>>size;
  subsequence(a,size,n);
  for(auto i : ans){
    for(auto j : i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}