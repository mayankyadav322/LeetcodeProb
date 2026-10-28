class Solution {
public:
    int helper(vector<int>& prices,int i,int buy,vector<vector<vector<int>>>& dp,int limit){
        if(i == prices.size())
        return 0;
        if(limit == 0)
        return 0;
        if(dp[i][buy][limit] != -1)
        return dp[i][buy][limit];
        int profit;
        
        if(buy == 1){
            profit = max(-prices[i] + helper(prices,i+1,0,dp,limit),helper(prices,i+1,1,dp,limit));
        }
        else{
            profit = max(prices[i] + helper(prices,i+1,1,dp,limit-1),helper(prices,i+1,0,dp,limit));
        }
        
     return dp[i][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int i =0;
        int n = prices.size();
        int buy = 1;
        int limit = 2;
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return helper(prices,i,buy,dp,limit);
    }
};