#include <bits/stdc++.h>
using namespace std;

struct mycmp

vector<int> kclosest(vector<int>a,int k){
  priority_queue<int,vector<int>,mycmp>pq;
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(auto &i:a) cin>>i;
  int x;
  cout<<"Enter the required element : "<<
  cin>>x;
  int k;
  cout<<"Enter the value of k : ";
  cin>>k;
  vector<int> ans = kclosest(a,k);
  return 0;
}