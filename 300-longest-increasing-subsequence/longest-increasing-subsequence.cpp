class Solution {
public:
    int subsequence(vector<int>& nums,int i,int prev,vector<vector<int>>& dp){
    if(i == nums.size())
    return 0;
    if(dp[i][prev+1] != INT_MAX)
    return dp[i][prev+1];
    int include = 0;
    if(prev == -1 || nums[i] > nums[prev]){
         include = 1 + subsequence(nums,i+1,i,dp);
    }   
    int skip = subsequence(nums,i+1,prev,dp);
    return  dp[i][prev+1] = max(include,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
       int i = 0;
       int prev = -1;
       int n = nums.size();
       vector<vector<int>> dp(n,vector<int> (n+1,INT_MAX));
       return subsequence(nums,i,prev,dp); 
    }
};