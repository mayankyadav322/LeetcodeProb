class Solution {
public:
void solver(vector<int>& candidates,int target,int index,vector<int>& current,vector<vector<int>>& ans,int sum){
    if(target == sum){
        ans.push_back(current);
    return;
    }
    if(sum > target || index >= candidates.size())
    return;
    current.push_back(candidates[index]);
    solver(candidates,target,index,current,ans,sum+candidates[index]);
      current.pop_back();   
    solver(candidates,target,index+1,current,ans,sum);
        
   
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0;
        vector<int> current;
        vector<vector<int>> ans;
        int sum=0;
        solver(candidates,target,index,current,ans,sum);
        return ans;
    }
};