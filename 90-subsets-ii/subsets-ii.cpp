class Solution {
public:
    void solver(vector<int>& nums,int index,vector<int> current,vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        solver(nums,index+1,current,ans);
        current.pop_back();
        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
         solver(nums,index+1,current,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index=0;
        vector<int> current;
        vector<vector<int>> ans;
        solver(nums,index,current,ans);
        return ans;
    }
};