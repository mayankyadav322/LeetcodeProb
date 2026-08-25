class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       unordered_map<int,int> mp; 
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
       }
       int j=1;int ans=0;
       while(true){
        if(!mp.count(k*j)){
             ans = k*j;
             break;
        }
        j++;

       }
       return ans;
    }
};