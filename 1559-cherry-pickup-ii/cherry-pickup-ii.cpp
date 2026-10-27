class Solution {
public:
    int helper(vector<vector<int>>& grid,int m,int n,int i,int j,int k,vector<vector<vector<int>>>& dp){
        if(i >= m || j >= n || j < 0 || k >= n || k < 0)
        return -1e9;
        if(i == m-1){
           if(j == k)
           return grid[i][j];
        return grid[i][j]+grid[i][k];
        }
        if(dp[i][j][k] != -1)
        return dp[i][j][k];
        int move1 = helper(grid, m, n, i+1, j-1, k-1, dp);
        int move2 = helper(grid, m, n, i+1, j-1, k, dp);
        int move3 = helper(grid, m, n, i+1, j-1, k+1, dp);

        int move4 = helper(grid, m, n, i+1, j, k-1, dp);
        int move5 = helper(grid, m, n, i+1, j, k, dp);
        int move6 = helper(grid, m, n, i+1, j, k+1, dp);

        int move7 = helper(grid, m, n, i+1, j+1, k-1, dp);
        int move8 = helper(grid, m, n, i+1, j+1, k, dp);
        int move9 = helper(grid, m, n, i+1, j+1, k+1, dp); 
        int maxi = max({move1,move2,move3,move4,move5,move6,move7,move8,move9});
        int cherries = grid[i][j];
        if(j != k)
        cherries = cherries+grid[i][k];
        return dp[i][j][k] = cherries+maxi;


    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i=0,j=0,k=n-1;
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (n,-1)));
        return max(0,helper(grid,m,n,i,j,k,dp));
    }
};