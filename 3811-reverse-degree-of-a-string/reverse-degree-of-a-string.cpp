class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int product = ('z' - s[i] +1)*(i+1);
            ans = ans+product;
        }
        return ans;
    }
};