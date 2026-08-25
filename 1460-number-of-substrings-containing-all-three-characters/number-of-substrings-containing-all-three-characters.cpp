class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
     int n=s.length();
     int left=0;
     int result=0;
     for(int right=0;right<n;right++){
        mp[s[right]]++;
        while(mp.size() == 3){
            result = result + (n - right);
            mp[s[left]]--;
            if(mp[s[left]] ==0){
                mp.erase(s[left]);
            }
            left++;
        }
     }

        return result;
    }
};