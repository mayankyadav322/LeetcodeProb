class Solution {
public:
    int solver(vector<vector<int>>& matrix,int m,int n,int i,int j,int sum,vector<vector<int>>& dp){
        if(j < 0 || j >= n)
        return INT_MAX;
        if(i == m-1)
        return matrix[i][j];
        if(dp[i][j] != INT_MAX)
        return dp[i][j];
        int left = solver(matrix,m,n,i+1,j-1,sum+matrix[i][j],dp);
        int down = solver(matrix,m,n,i+1,j,sum+matrix[i][j],dp);
        int right = solver(matrix,m,n,i+1,j+1,sum+matrix[i][j],dp);

        return dp[i][j] =  matrix[i][j] + min(left,min(down,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = 0;
        int sum = 0;
        vector<vector<int>> dp(m,vector<int> (n,INT_MAX));
        int ans = INT_MAX;
        for(int j=0;j<n;j++){
        ans = min(ans,solver(matrix,m,n,i,j,sum,dp));
        }
        return ans;
    }
};