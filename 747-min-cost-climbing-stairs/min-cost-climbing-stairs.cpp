class Solution {
public:
    int solver(int n,vector<int>& dp,vector<int>& cost){
        if(n == 0)
        return cost[0];
        if(n == 1)
        return cost[1];
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = cost[n] + min(solver(n-1,dp,cost),solver(n-2,dp,cost));
        return dp[n];
        }
 
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        int ans = min(solver(n-1,dp,cost),solver(n-2,dp,cost));
        return ans;
        
    }
};