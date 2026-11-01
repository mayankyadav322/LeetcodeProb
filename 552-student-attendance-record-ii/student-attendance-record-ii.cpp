class Solution {
public:
    const int MOD = 1e9 + 7;

    long long solver(int n, int absent, int late,
                     vector<vector<vector<long long>>>& dp) {
        

        if(n == 0)
            return 1;

        if(dp[n][absent][late] != -1)
            return dp[n][absent][late];

        long long ans = solver(n-1, absent, 0, dp);

        if(absent < 1) {
            ans = (ans + solver(n-1, absent+1, 0, dp)) % MOD;
        }

        if(late < 2) {
            ans = (ans + solver(n-1, absent, late+1, dp)) % MOD;
        }

        return dp[n][absent][late] = ans;
    }

    int checkRecord(int n) {
        vector<vector<vector<long long>>> dp(
            n+1, vector<vector<long long>>(
                2, vector<long long>(3, -1)
            )
        );

        return solver(n, 0, 0, dp);
    }
};