class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
       for(int i=n-1;i>=0;){
        int k= false;
        for(int j=0;j<i;j++){
            if(j + nums[j] >= i){
                i = j;
                k = true;
                ans++;
            }
            
        }
        if(i == 0) return ans;
        if(k == false) return -1;
       }
       return ans;
    }
};