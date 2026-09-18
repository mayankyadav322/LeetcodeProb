class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
       for (string str : strs){
        string temp = str;
        sort(temp.begin(),temp.end());
        mp[temp].push_back(str);
       }
       vector<vector<string>> ans;
       for(auto& [key,value] : mp){
        ans.push_back(value);
       }
        return ans;
    }
};