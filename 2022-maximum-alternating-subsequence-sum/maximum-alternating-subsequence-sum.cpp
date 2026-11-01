class Solution {
public:
    long long helper(vector<int>& nums, int i, int sign,vector<vector<long long>>& dp) {
    if(i >= nums.size())
        return 0;
        int state = (sign == 1) ? 0 : 1;
if(dp[i][state] != -1)
return dp[i][state];
    long long take = sign * nums[i] + helper(nums, i+1, -sign,dp);
    long long skip = helper(nums, i+1, sign,dp);

    return  dp[i][state] =  max(take, skip);
}
    long long maxAlternatingSum(vector<int>& nums) {
        int i = 0;
       int sign = 1;
       int n = nums.size();
       vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return helper(nums,i,sign,dp);
    }
};