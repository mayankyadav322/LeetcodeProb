class Solution {
public:
int solver(int n,vector
<int>& dp,vector<int>& nums){
    if(n == 0)
    return nums[0];
    if(n == 1)
    return max(nums[0],nums[1]);
    if(dp[n] != -1)
    return dp[n];
    int first = nums[n] + solver(n-2,dp,nums);
    int second = solver(n-1,dp,nums);
    dp[n] = max(first,second);
    
    return dp[n];
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        if(n == 1) return nums[0];
        return solver(n-1,dp,nums);
    }
};