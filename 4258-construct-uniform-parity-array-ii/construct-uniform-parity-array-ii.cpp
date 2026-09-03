class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;
        int count = 0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2 != 0){
                min_odd = min(min_odd,nums1[i]);
            }
            else if(nums1[i]%2 == 0){
                min_even = min(min_even,nums1[i]);
                count++;
            }
        }
        if(count == nums1.size()) return true;
        if(min_even < min_odd) return false;
         return true;
    }
};