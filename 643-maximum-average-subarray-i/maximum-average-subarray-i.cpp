class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg = INT_MIN;
        int low=0;
        int high=0;
        int res=0;
        while(high<nums.size()){
            res = res + nums[high];
            if(high-low+1 == k){
            double avg= (double)res/(high-low+1);
            maxavg = max(maxavg,avg);
           res = res - nums[low];
           low++;
        }
        high++;
        }
       return maxavg;
    }
};