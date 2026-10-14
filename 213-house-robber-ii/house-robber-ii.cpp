class Solution {
public:
    int solver(int index,int n,vector<int>& dp,vector<int>& nums){
        if(n < index)
        return 0;
        if(n == index)
        return nums[n];
        
        if(dp[n] != -1)
        return dp[n];
        int first =  nums[n] + solver(index,n-2,dp,nums);
        int second = solver(index,n-1,dp,nums);
       return dp[n] = max(first,second);
        
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
         int first = solver(0,n-2,dp1,nums);
         int second = solver(1,n-1,dp2,nums);
        return max(first,second);
    }
};