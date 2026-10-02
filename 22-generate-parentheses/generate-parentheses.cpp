class Solution {
public:
    void solver(int n,int left,int right,string current,vector<string>& ans){
       
         if(left == n && right == n){
              
              ans.push_back(current);
              return;
         }
              if(left<n){
                solver(n,left+1,right,current + '(',ans);
              }
              if(right<left){
                solver(n,left,right+1,current + ')',ans);
              }
             
         
    }
    vector<string> generateParenthesis(int n) {
        int left=0;
        int right=0;
         string current;
       vector<string> ans;
        solver(n,left,right,current,ans);
        return ans;
    }
};