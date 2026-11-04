class Solution {
public:
    int helper(vector<int>& nums,int target,int i,int sum,vector<vector<int>>& dp){
       if(i == nums.size())
       return sum == target;
       if(dp[i][sum+1000] != -1)
       return dp[i][sum+1000];
        
      int plus =   helper(nums,target,i+1,sum+nums[i],dp);
      int minus =   helper(nums,target,i+1,sum-nums[i],dp);
       return dp[i][sum+1000] = plus+minus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int i = 0;
        int sum = 0;
        
        vector<vector<int>> dp(nums.size(),vector<int> (2001,-1));
       return helper(nums,target,i,sum,dp);
        
    }
};