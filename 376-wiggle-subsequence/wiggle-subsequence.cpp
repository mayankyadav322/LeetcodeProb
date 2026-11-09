
class Solution {
public:
    int helper(vector<int>& nums, int i, int prev, int direction,
               vector<vector<vector<int>>>& dp) {

        if(i == nums.size())
            return 0;

        if(dp[i][prev+1][direction+1] != -1)
            return dp[i][prev+1][direction+1];

        int include = 0;

        if(prev == -1) {
            include = 1 + helper(nums, i+1, i, 0, dp);
        }
        else if(direction == 0) {
            if(nums[i] > nums[prev])
                include = 1 + helper(nums, i+1, i, 1, dp);

            else if(nums[i] < nums[prev])
                include = 1 + helper(nums, i+1, i, -1, dp);
        }
        else if(direction == -1 && nums[i] > nums[prev]) {
            include = 1 + helper(nums, i+1, i, 1, dp);
        }
        else if(direction == 1 && nums[i] < nums[prev]) {
            include = 1 + helper(nums, i+1, i, -1, dp);
        }

        int skip = helper(nums, i+1, prev, direction, dp);

        return dp[i][prev+1][direction+1] = max(include, skip);
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int prev = -1;
        int direction = 0;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n+1, vector<int>(3, -1))
        );

        return helper(nums, 0, -1, 0, dp);
    }
};
