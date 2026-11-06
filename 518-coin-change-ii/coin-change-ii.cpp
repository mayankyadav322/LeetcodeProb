class Solution {
public:
    int helper(int amount,vector<int>& coins,int i,int sum,vector<vector<int>>& dp){
        if(i == coins.size()){
            if(sum == amount)
            return 1;
            return 0;
        }
        if(sum > amount)
        return 0; 
        if(dp[i][sum] != -1)
        return dp[i][sum];      
         int exclude = helper(amount,coins,i+1,sum,dp);
        
        int include = helper(amount,coins,i,sum+coins[i],dp);
      return  dp[i][sum] = include + exclude;
    }
    int change(int amount, vector<int>& coins) {
        int i = 0;
        int sum = 0;
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        return helper(amount,coins,i,sum,dp);
    }
};