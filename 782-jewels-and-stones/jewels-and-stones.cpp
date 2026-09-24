class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> hash;
        for(char c : stones){          
            hash[c]++;
        }
        int ans=0;
        for(char c : jewels){
            if(hash[c] > 0){
                ans = ans+hash[c];
            }
        }
        return ans;
    }
};