//count elements smaller or equal to theh curr element. when a greater element comes stop there
#include <bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> a){
  stack<int> s;
  vector<int> ans;
  ans.push_back(1);
  s.push(0);
  for(int i=1;i<a.size();i++){
    while(s.empty()==false && a[i]>=a[s.top()]){
      s.pop();
    }
    int x= s.empty() ? i+1 : i-s.top();
    ans.push_back(x);
    s.push(i);
  }
  return ans;
}

void print(vector<int> &a){
  for(auto i:a) cout<<i<<"  ";
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(auto &i:a) cin>>i;
  vector<int> ans=stockspan(a);
  print(ans);
  return 0;
}