class Solution {
public:
    int helper(vector<int>& prices,int i,int buy,vector<vector<int>>& dp){
        if(i >= prices.size())
        return 0;       
        if(dp[i][buy] != -1)
        return dp[i][buy];
        int profit;
        if(buy == 1){
            profit = max(-prices[i] + helper(prices,i+1,0,dp),helper(prices,i+1,1,dp));
        }
        else{
            profit = max(prices[i] + helper(prices,i+2,1,dp),helper(prices,i+1,0,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i=0;
        int buy = 1;
        if(n == 1)
        return 0;
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return helper(prices,i,buy,dp);
    }
};