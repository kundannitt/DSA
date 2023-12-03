#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<int>>arr= {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  cout<<"Before"<<endl;
  for(auto i : arr){
    for(auto j : i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  int top = 0;
  int bottom = arr.size() - 1;
  int left = 0;
  int right = arr[0].size() - 1;
  vector<vector<int>>ans = arr;
  vector<int>temp;
  while(left <= right && top <= bottom){
    for(int i=left;i<=right;i++){
      temp.push_back(arr[top][i]);
    }
    top++;
    for(int i=top;i<=bottom;i++){
      temp.push_back(arr[i][right]);
    }
    right--;
    for(int i=right;i>=left;i--){
      temp.push_back(arr[bottom][i]);
    }
    bottom--;
    for(int i=bottom;i>=top;i--){
      temp.push_back(arr[i][left]);
    }
    left++;
  }
  int x = 0;
  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[0].size();j++){
      ans[i][j] = temp[x++];
    }
  }
  cout<<endl;
  for(auto i : ans){
    for(auto j : i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}