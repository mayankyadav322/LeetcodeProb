class Solution {
public:
int ans =0;
    int solver(vector<vector<int>>& grid,int m,int n,int i,int j,int sum,vector<vector<int>>& dp){
        if(i >= m || j >= n)
        return INT_MAX;
        if(i == m-1 && j == n-1)
        return grid[i][j];
        if(dp[i][j] != -1)
        return dp[i][j];
        int lh = solver(grid,m,n,i,j+1,sum+grid[i][j],dp);
        int rh = solver(grid,m,n,i+1,j,sum+grid[i][j],dp);
        
        dp[i][j] =  grid[i][j]+min(lh,rh);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i=0;
        int j=0;
        int sum=0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solver(grid,m,n,i,j,sum,dp);
    }
};