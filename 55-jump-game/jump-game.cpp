class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size();
       for(int i=n-1;i>=0;){
        int k= false;
        for(int j=0;j<i;j++){
            if(j + nums[j] >= i){
                i = j;
                k = true;
            }
            
        }
        if(i == 0) return true;
        if(k == false) return false;
       }
       return true;
    }
};