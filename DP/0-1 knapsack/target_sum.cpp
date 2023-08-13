int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(),nums.end(),0);
    /* the question is that 'is it possible to partiton the 
    array in two subset such that their difference is equal 
    to target.
    => s2-s1 = target;
    => s2+s1 = sum;
    => sum-2*s1 = target; 
    => s1 = (sum-target)/2; // we have to find this.
    */
    if((sum-target)<0){
      return 0;
    }
    return ispossible(nums,nums.size(),(sum-target)/2);
  }
  int ispossible(vector<int>nums,int n,int sum){
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    for(int i=0;i<n+1;i++){
      for(int j=0;j<sum+1;j++){
        if(i==0){
          dp[i][j] = 0;
        }
        if(j==0){
          dp[i][j] = 1;
        }
      }
    }
    for(int i=1;i<n+1;i++){
      for(int j=1;j<sum+1;j++){
        if(nums[i-1] <= j){
          dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
        }else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
    // for(int i=0;i<n+1;i++){
    //   for(int j=0;j<sum+1;j++){
    //     cout<<dp[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    return dp[n][sum];
  }