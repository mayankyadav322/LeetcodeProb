class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int low = 0;
        int high = nums.size() - 1;
        int first = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if(first != -1) {
            while(first < nums.size() && nums[first] == target) {
                ans.push_back(first);
                first++;
            }
        }

        return ans;
    }
};