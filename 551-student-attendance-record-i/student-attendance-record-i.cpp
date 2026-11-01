class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        long long countA = 0;
        
        for(int i=0;i<n;i++){
           if(s[i] == 'A') countA++;
           else if(s[i] == 'L'){
            long long countL = 0;
            while( i < n && s[i] == 'L'){
                countL++;
                i++;
            }
            
            if(countL >= 3) return false;
            i--;
           }
          
        }
        if(countA > 1) return false;
        return true;
    }
};