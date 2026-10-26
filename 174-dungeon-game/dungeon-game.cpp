class Solution {
public:

    int helper(vector<vector<int>>& dungeon,int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i >= m || j >= n)
        return 1e9;
        if(i == m-1 && j == n-1)
        return dp[i][j] = max(1,1-dungeon[i][j]);
        if(dp[i][j] != -1)
        return dp[i][j];
        int right = helper(dungeon,m,n,i,j+1,dp);
        int down = helper(dungeon,m,n,i+1,j,dp);
        int next = min(right,down);
        int need = max(1,next-dungeon[i][j]);
        return dp[i][j] = need;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(dungeon,m,n,i,j,dp); 
    }
};