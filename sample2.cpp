#include <bits/stdc++.h>
using namespace std;

void sort(vector<int> &a){
  priority_queue<int,vector<int>,greater<int>> pq(a.begin(),a.end());
  int low =0;
  while(pq.empty()==false){
    a[low] = pq.top();
    pq.pop();
    low++;
  }
}

void print(vector<int> a){
  for(auto i:a) cout<<i<<" ";
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(auto &i:a) cin>>i;
  sort(a);
  print(a);
  return 0;
}