#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int i,int j){
  if(i>=j){
    return 0;
  }
  int ans = INT_MAX;
  for(int k=i;k<j;k++){
    int temp_ans = solve(arr,i,k) + solve(arr,k+1,j) + (arr[i-1] * arr[k] * arr[j]); //(arr[i-1] * arr[k] * arr[j]) gives cost. 
    ans = min(ans,temp_ans);
  }
  return ans;
}

int main(){
  int n;
  cin>>n;
  vector<int>dimensions(n);
  for(auto &i:dimensions) cin>>i;
  cout<<solve(dimensions,1,n-1);
  return 0;
}