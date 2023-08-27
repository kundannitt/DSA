class Solution {
public:
  set<vector<int>>st;
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int>out;
    solve(nums,0,out);
    vector<vector<int>>ans;
    for(auto i:st){
      ans.push_back(i);
    }
    return ans;
  }
  void solve(vector<int>&nums,int index,vector<int>&out){
    if(index == nums.size()){
      if(out.size() >= 2){
        st.insert(out);
      }
      return;
    }
    if(out.size() == 0 || out.back()<=nums[index]){
      out.push_back(nums[index]);
      solve(nums,index+1,out);
      out.pop_back();
    }
    solve(nums,index+1,out);
  }
};