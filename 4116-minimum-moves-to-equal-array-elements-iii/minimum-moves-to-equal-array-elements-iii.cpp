class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int result = maxi-nums[i];
            count = count + result;
        }
        return count;
    }
};