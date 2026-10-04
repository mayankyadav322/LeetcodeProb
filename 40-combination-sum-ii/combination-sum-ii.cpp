class Solution {
public:
    void solver(vector<int>& candidates,int target,int index,int sum,vector<int>& current,vector<vector<int>>& ans){
        if(target == sum){
            ans.push_back(current);
            return;
        }
        if(sum > target || index >= candidates.size())
        return;
        current.push_back(candidates[index]);
        solver(candidates,target,index+1,sum+candidates[index],current,ans);
        current.pop_back();
        while(index + 1 < candidates.size() &&
      candidates[index] == candidates[index + 1]){
        index++;
      }
       solver(candidates,target,index+1,sum,current,ans);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int index=0;
        int sum=0;
        vector<int> current;
        vector<vector<int>> ans;
        solver(candidates,target,index,sum,current,ans);
        return ans;
    }
};