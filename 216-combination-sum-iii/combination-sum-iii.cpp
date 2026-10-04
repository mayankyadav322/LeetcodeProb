class Solution {
public:
    void solver(int k,int n, int index,vector<int> current,vector<vector<int>>& ans,int sum,vector<int>& candidates,int count){
       
        if( count==k && n == sum){
            ans.push_back(current);
            return;
        }
         if(count > k || sum > n || index >= 9){
            return;
        }
        
        current.push_back(candidates[index]);
        
        solver(k,n,index+1,current,ans,sum+candidates[index],candidates,count+1);
        
        
        current.pop_back();
        
        solver(k,n,index+1,current,ans,sum,candidates,count);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int index=0;
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        vector<int> current;
        vector<vector<int>> ans;
        int sum=0;
        int count=0;
        solver(k,n,index,current,ans,sum,candidates,count);
        return ans;
    }
};