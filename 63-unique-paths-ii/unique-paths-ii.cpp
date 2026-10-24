class Solution {
public:
    int solver(vector<vector<int>>& obstacleGrid,int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i >= m || j >= n)
        return 0;
        if(obstacleGrid[i][j] == 1)
        return 0;
        if(i == m-1 && j == n-1)
        return 1;       
        if(dp[i][j] != -1)
        return dp[i][j];
        dp[i][j] =  solver(obstacleGrid,m,n,i,j+1,dp) + solver(obstacleGrid,m,n,i+1,j,dp);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i=0;
        int j=0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solver(obstacleGrid,m,n,i,j,dp);

    }
};