#include <bits/stdc++.h>
using namespace std;
bool next_perm(vector<int> &nums){
  int j=-1;
  for(int i=0;i<nums.size()-1;i++){
    if(nums[i]<nums[i+1]){
      j=i;
    }
  }

  if(j==-1) return false;
  
  int i=j+1;
  for(int k=j+1;k<nums.size();k++){
    if(nums[j]<nums[k]){
      i=k;
    }
  }
  swap(nums[i],nums[j]);
  reverse(nums.begin()+j+1,nums.end());
  return true;
  }
vector<vector<int>> permute(vector<int>& nums) {
  set<vector<int>> st;
  vector<vector<int>>ans;
  sort(nums.begin(),nums.end());

  do{
    st.insert(nums);
  }
  while(next_perm(nums));

  for(auto it=st.begin();it!=st.end();it++){
    ans.push_back(*it);
  }
  return ans;
}

int main(){
  vector<int> a={2,3,4,6};
  vector<vector<int>> ans=permute(a);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[0].size();j++){
      cout<<ans[i][j]<<" ";
    }
  cout<<endl;
  }
  return 0;
}