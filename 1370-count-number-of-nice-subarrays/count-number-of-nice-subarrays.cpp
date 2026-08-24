class Solution {
public:
int atMost(vector<int>& nums, int k) {
 int n = nums.size();
        int count=0;
        int left=0;
        int odd=0;
        for(int right=0;right<n;right++){
            
            if(nums[right] %2 != 0){
                odd++;
            }
            while(odd>k){
                if(nums[left] %2 != 0)
                    odd--;
                    left++;
                }
                count = count + (right-left+1);
            
        }
        return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};