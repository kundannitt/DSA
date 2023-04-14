#include <bits/stdc++.h>
using namespace std;

vector<int> prevGreater(vector<int> a){
  reverse(a.begin(),a.end());
  stack<int>s;
  vector<int> ans;
  s.push(0);
  ans.push_back(-1);

  for(int i=1;i<a.size();i++){
    while(s.empty()==false && a[i]>=a[s.top()]){
      s.pop();
    }
    int x = s.empty() ? -1 : a[s.top()];
    ans.push_back(x);
    s.push(i); 
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

void print(vector<int> &a){
  for(auto i:a) cout<<i<<" ";
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(auto &i:a) cin>>i;
  vector<int> ans=prevGreater(a);
  print(ans);
  return 0;
}