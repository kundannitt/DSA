#include <bits/stdc++.h>
using namespace std;

vector<int> alldivisors(int n){
  int i=0;
  vector<int> ans;
  for(i=1;i*i<n;i++){
    if(n%i==0){
      if(n/i==i){
        ans.push_back(i);
      }else{
        ans.push_back(i);
        ans.push_back(n/i); // to print in sorted order . store this n/i value in some other array and print in reverse order.
      }
    }
  }
  return ans;
}

void print(vector<int> a){
  for(auto i:a){
    cout<<i<<" ";
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> ans = alldivisors(n);
  print(ans);
  return 0;
}