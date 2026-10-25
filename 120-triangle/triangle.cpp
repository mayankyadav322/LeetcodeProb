class Solution {
public:
    int solver(vector<vector<int>>& triangle,int m,int n,int i,int j,int sum,vector<vector<int>>& dp){
        if(i >= m || j >= triangle[i].size())
        return INT_MAX;
        if(i == m-1)
        return triangle[i][j];
        if(dp[i][j] != INT_MAX)
        return dp[i][j];
        int lh = solver(triangle,m,n,i+1,j,sum+triangle[i][j],dp);
        int rh = solver(triangle,m,n,i+1,j+1,sum+triangle[i][j],dp);
        dp[i][j] = triangle[i][j] + min(lh,rh);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        vector<vector<int>> dp(m,vector<int> (n,INT_MAX));
        return solver(triangle,m,n,i,j,sum,dp);
    }
}; 