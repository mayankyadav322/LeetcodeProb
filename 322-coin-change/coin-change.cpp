class Solution {
public:
int solve(vector<int>& coins,int amount,int sum,int index,vector<vector<int>>& dp){
     if(sum == amount)
        return 0;
     if(sum > amount || index >= coins.size())
     return 1000000;
     if(dp[sum][index] != -1)
     return dp[sum][index];
    int include = 1000000;
    if(coins[index] <= amount-sum)
      include = 1+solve(coins,amount,sum+coins[index],index,dp);
    int exclude = solve(coins,amount,sum,index+1,dp);
     return dp[sum][index] =  min(include,exclude);

     
}
    int coinChange(vector<int>& coins, int amount) {
    int sum =0;
    int index=0;
        vector<vector<int>> dp(amount + 1,
                               vector<int>(coins.size(), -1));
        int ans =  solve(coins,amount,sum,index,dp);
       if(ans == 1000000){
        return -1;
       }
      
        return ans;
    }
};