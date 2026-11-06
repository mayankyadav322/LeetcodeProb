class Solution {
public:
    int helper(int n, int i, int sum, vector<int>& squares,
               vector<vector<int>>& dp) {
        if (sum == n)
            return 0;

        if (sum > n || i == squares.size())
            return 1e9;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int include = 1e9;

        if (sum + squares[i] <= n) {
            include = 1 + helper(n, i, sum + squares[i], squares, dp);
        }

        int exclude = helper(n, i + 1, sum, squares, dp);

        return dp[i][sum] = min(include, exclude);
    }

    int numSquares(int n) {
        vector<int> squares;

        for (int j = 1; j * j <= n; j++) {
            squares.push_back(j * j);
        }

        vector<vector<int>> dp(
            squares.size(), vector<int>(n + 1, -1)
        );

        return helper(n, 0, 0, squares, dp);
    }
};