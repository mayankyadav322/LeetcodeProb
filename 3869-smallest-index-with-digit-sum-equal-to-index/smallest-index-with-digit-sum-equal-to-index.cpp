class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int f = nums[i];
         int sum=0;
            while(f>0){
            sum = sum+ f%10;
            f=f/10;
            }
            if(sum == i) return sum;
        }
        return -1;
    }
};