class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=0;
        for(int i=0;i<accounts.size();i++){
            int sum2=0;
        
        for(int j=0;j<accounts[i].size();j++){
            sum2 = sum2+accounts[i][j];
            maxi = max(maxi,sum2);
        }
        }
        return maxi;
    }
};