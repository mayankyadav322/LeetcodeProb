class Solution {
public:
    bool helper(vector<int>& nums,int target,int i,int sum,vector<vector<int>>& dp){
        if(sum == target)
        return true;
        if(i >= nums.size() || sum > target)
        return false;
        if(dp[i][sum] != -1)
        return dp[i][sum];
        return dp[i][sum]  = helper(nums,target,i+1,sum+nums[i],dp) || helper(nums,target,i+1,sum,dp);
    }
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int totalsum = 0;
       for(int i=0;i<nums.size();i++){
        totalsum = totalsum + nums[i];
       }
       if(totalsum%2 != 0) return false;
       int target = totalsum/2;
       int i = 0;
       int sum = 0;
       vector<vector<int>> dp(n,vector<int> (target+1,-1));
       return helper(nums,target,i,sum,dp);

    }
};