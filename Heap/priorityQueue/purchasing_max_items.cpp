#include <bits/stdc++.h>
using namespace std;

int maxitems(vector<int>a,int sum){
  priority_queue<int,vector<int>,greater<int>>pq(a.begin(),a.end());
  int count = 0;
  int curr_sum = 0;
  while(pq.empty()==false){
    curr_sum += pq.top();
    pq.pop();
    if(curr_sum > sum){
      return count;
    }
    count++;
  }
  return -1;
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for (auto &i:a) cin>>i;
  int sum;
  cout<<"The max sum is : ";
  cin>>sum;
  cout<<maxitems(a,sum);
  return 0;
}