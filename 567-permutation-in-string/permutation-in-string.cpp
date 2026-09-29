class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
       sort(s1.begin(),s1.end());
      

        int left=0;
        int right=0;
        while(right<s2.size()){
            if(right-left+1 == n){
            string temp = s2.substr(left,n);
            sort(temp.begin(),temp.end());
            
            if(s1 == temp){
             return true;  
            }        
              left++;
            }
            right++;
        }
        return false;
    }
};