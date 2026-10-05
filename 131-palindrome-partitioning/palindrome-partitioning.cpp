class Solution {
public:
    void solver(string s,int index,vector<vector<string>>& ans,vector<string> current){
        if(index >= s.length()){
            ans.push_back(current);
            return;
        }
        for(int i=index;i<s.length();i++){
          string result = s.substr(index,i-index+1); 
          int left=0;
          int right=result.length()-1;
          bool ispalindrome = true;
          while(left<=right){
            if(result[left] != result[right]){
                 ispalindrome = false;
                 break;
            }
            left++;
            right--;
          }
          if(ispalindrome){
            current.push_back(result);
            solver(s,i+1,ans,current);
            current.pop_back();
          }
        }
    }
    vector<vector<string>> partition(string s) {
        int index=0;
        vector<vector<string>> ans;
        vector<string> current;
        solver(s,index,ans,current);
        return ans;
    }
};