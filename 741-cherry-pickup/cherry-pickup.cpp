class Solution {
public:
    int solver(vector<vector<int>>& grid,int i1,int j1,int i2,int j2,int n,vector<vector<vector<vector<int>>>>& dp){
        if(i1 >= n || j1 >= n || i2 >= n || j2 >= n)
        return -1e9;
        if(grid[i1][j1] == -1 || grid[i2][j2] == -1)
        return -1e9;
        if(i1 == n-1 && j1 == n-1 && i2 == n-1 && j2 == n-1)
        return grid[n-1][n-1];       
        if(dp[i1][j1][i2][j2] != -1)
        return dp[i1][j1][i2][j2];
        int move1 = solver(grid,i1+1,j1,i2+1,j2,n,dp);
        int move2 = solver(grid,i1,j1+1,i2,j2+1,n,dp);
        int move3 = solver(grid,i1+1,j1,i2,j2+1,n,dp);
        int move4 = solver(grid,i1,j1+1,i2+1,j2,n,dp);
         int cherries = grid[i1][j1];

        if (i1 != i2 || j1 != j2)
            cherries += grid[i2][j2];
        return dp[i1][j1][i2][j2] = cherries + max({move1,move2,move3,move4});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int i1 = 0,i2 = 0,j1 = 0,j2 = 0;
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return  max(0,solver(grid,i1,j1,i2,j2,n,dp));
       
    }
};