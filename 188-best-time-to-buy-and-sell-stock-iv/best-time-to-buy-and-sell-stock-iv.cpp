class Solution {
public:
    int helper(int k,vector<int>& prices,int i,int buy,vector<vector<vector<int>>>& dp){
        if(i == prices.size())
        return 0;
        if(k == 0)
        return 0;
        if(dp[i][buy][k] != -1)
        return dp[i][buy][k];
        int profit;
        if(buy == 1){
            profit = max(-prices[i] + helper(k,prices,i+1,0,dp),helper(k,prices,i+1,1,dp));
        }
        else{
            profit = max(prices[i] + helper(k-1,prices,i+1,1,dp),helper(k,prices,i+1,0,dp));
        }
        return dp[i][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int i=0;
        int buy = 1;
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return helper(k,prices,i,buy,dp);
    }
};