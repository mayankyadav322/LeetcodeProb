class Solution {
public:
    int helper(vector<int>& stones, int i, int sum1, int total,
               vector<vector<int>>& dp) {
        if (i == stones.size())
            return abs(sum1 - (total - sum1));

        if (dp[i][sum1] != -1)
            return dp[i][sum1];

        int include = helper(stones, i + 1, sum1 + stones[i], total, dp);
        int exclude = helper(stones, i + 1, sum1, total, dp);

        return dp[i][sum1] = min(include, exclude);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        for (int stone : stones)
            total += stone;

        vector<vector<int>> dp(
            stones.size(), vector<int>(total + 1, -1)
        );

        return helper(stones, 0, 0, total, dp);
    }
};