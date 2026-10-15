class Solution {
public:
    int solver(vector<int>& nums,unordered_map<int,int>& mp,int index,vector<int>& dp){
        if(index >= nums.size())
        return 0;
        if(dp[index] != -1)
        return dp[index];
        int take = nums[index]*mp[nums[index]];
        int next = index + 1;
        if(next < nums.size() && nums[next] == nums[index]+1)
          next++;
            take  = take + solver(nums,mp,next,dp);
            int skip = solver(nums,mp,index+1,dp);
            return dp[index] = max(take,skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int index = 0;
        for(int x : nums){
            mp[x]++;
        }
        vector<int> values;
        for(auto& p : mp){
            values.push_back(p.first);
        }
        sort(values.begin(),values.end());
        vector<int> dp(values.size(),-1);
       int ans =  solver(values,mp,index,dp);
       return ans;
    }
};