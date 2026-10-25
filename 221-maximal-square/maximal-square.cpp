class Solution {
public:
    int solver(vector<vector<char>>& matrix,int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i < 0 || j < 0)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        if(matrix[i][j] == '0')
        return dp[i][j] = 0;
        int top = solver(matrix,m,n,i-1,j,dp);
        int diagnol = solver(matrix,m,n,i-1,j-1,dp);
        int down = solver(matrix,m,n,i,j-1,dp);
        dp[i][j] = 1 + min(top,min(diagnol,down));
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int side = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
        
        side =  max(side,solver(matrix,m,n,i,j,dp));
        }
        }
        return side*side;
    }
};