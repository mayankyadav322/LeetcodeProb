class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int low =0;
        int high = nums.size()-1;
      int count=0;
        while(low<=high){
             
            if(nums[low] ==0 && nums[high] != 0){
                swap(nums[low],nums[high]);
                count++;
                low++;
                high--;  
            }
            else if(nums[low] != 0){
                low++;
            }
            
            else high--;
            
        }
        return count;
    }
};