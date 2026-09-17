class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
              prefix[i] = prefix[i-1]+nums[i];
        }
        vector<int> suffix(nums.size());
        suffix[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i] = suffix[i+1]+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(i == 0){
                if(suffix[i+1] == 0){
                    return i;
                }
            }
            else if(i == nums.size()-1){
                if(prefix[i-1] == 0){
                    return i;
                }
            }
            else if(prefix[i-1] == suffix[i+1]){
                return i;
            }
        }
        return -1;
    }
};