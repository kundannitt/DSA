#include <bits/stdc++.h>
using namespace std;

void printmaxK(vector<int>&a,int k){
  deque<int> dq;
  // first handle case upto size 'k' :-
  for(int i=0;i<k;i++){
    while(!dq.empty() && a[dq.back()]<a[i]){
      dq.pop_back(); // if curr last element  in deque is smaller than a[i] then it will not be considered for other coming subarrays also. 
    }
    dq.push_back(i);
  }

  for(int i=k;i<a.size();i++){
    cout<<a[dq.front()]<<" ";
    while(!dq.empty() && dq.front()<=i-k){
      dq.pop_back();
    }
    while(!dq.empty() && a[dq.back()]<a[i]){
      dq.pop_front();
    }
    dq.push_back(i);
  }
  cout<<a[dq.front()];
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(auto &i:a){
    cin>>i;
  }
  int k;
  cin>>k;
  printmaxK(a,k);
  return 0;
}