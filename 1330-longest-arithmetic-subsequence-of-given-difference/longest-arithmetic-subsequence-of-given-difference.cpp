class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
          int n = arr.size();
          int maxi = 1;
          unordered_map<int,int> dp;
          for(int i=0;i<n;i++){
           int prev = arr[i]-difference;
           dp[arr[i]] = 1 + dp[prev];
           maxi = max(maxi,dp[arr[i]]);
          }
        return maxi;
    }
};