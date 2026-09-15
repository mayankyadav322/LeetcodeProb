class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int ans=0;
        while(i<j){
            if(height[i] <= height[j]){
               if(leftmax <= height[i]){
                leftmax = height[i];
               }
               else ans = ans + (leftmax-height[i]);
               i++;
            }
            else{
                if(rightmax <= height[j]){
                    rightmax = height[j];
                    
                }
                else ans = ans +(rightmax-height[j]);
          j--;
            }
            
            
        }
        return ans;
    }
};