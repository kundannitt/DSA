//return min number of partition needed such that each partition is a palindrome.
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>memo(1001,vector<int>(1001,-1));
bool ispal(string s ,int i,int j){
  while(i<=j){
    if(s[i] != s[j]){
      return false;
    }
    i++;
    j--;
  } 
  return true;
}

int partition(string s ,int i,int j){
  if(i>=j){ // i>j => size is 0, i==j => size = 1, in both cases we need 0 partition.
    return 0;
  }
  if(ispal(s,i,j) == true){
    return 0;
  }
  if(memo[i][j] != -1){
    return memo[i][j];
  }
  int ans = INT_MAX;
  for(int k=i;k<j;k++){
    int tempans = partition(s,i,k) + partition(s,k+1,j) + 1;
    ans = min(ans,tempans);
  }
  return memo[i][j] = ans;
}

int main(){
  string s;
  cin>>s;
  cout<<partition(s,0,s.size()-1);
  return 0;
}