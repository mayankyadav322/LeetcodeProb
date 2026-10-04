class Solution {
public:
    void solver(string digits,vector<string>& ans,string current,int index,vector<string>& mapping){
         if(index >= digits.length()){
            ans.push_back(current);
            return;
         }
         int number = digits[index]-'0';
         string value = mapping[number];
         for(int i=0;i<value.length();i++){
            current = current+value[i];
             solver(digits,ans,current,index+1,mapping);
            current.pop_back();
         }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        
        string current;
        int index=0;
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solver(digits,ans,current,index,mapping);
        return ans;      
    }
};