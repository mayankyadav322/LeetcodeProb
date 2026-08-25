class Solution {
public:
    int maxScore(vector<int>& cardpoints, int k) {
        int sum=0;
    
        for(int i=0;i<k;i++){
             sum = sum +cardpoints[i];
        }
        int result=sum;
        if(k == cardpoints.size()) return sum;
        int  i = k-1;
        for(int j=cardpoints.size()-1;i>=0;j--){
            sum = sum-cardpoints[i];
            sum = sum + cardpoints[j];
             result = max(result,sum);
              i--;  

        }
        return result;
    }
};