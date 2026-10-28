class Solution {
public:
    int helper(vector<int>& prices,int fee,int i,vector<vector<int>>& dp,int buy){
        if(i == prices.size())
        return 0;
        if(dp[i][buy] != -1)
        return dp[i][buy];
        int profit;
        if(buy == 1){
          profit =  max(-prices[i] + helper(prices,fee,i+1,dp,0),helper(prices,fee,i+1,dp,1));
        }
        else{
            profit = max((prices[i]-fee) + helper(prices,fee,i+1,dp,1),helper(prices,fee,i+1,dp,0));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int i = 0;
        int buy =1;
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return helper(prices,fee,i,dp,buy);
    }
};