class Solution {
public:
    string reverseStr(string s, int k) {
        string ans ="";
        for(int i=0;i<s.size();i= i+2*k){
            string temp = s.substr(i,k);
             reverse(temp.begin(), temp.end());
              ans = ans + temp;
              if(i+k < s.size()){
             string temp2 =  s.substr(i+k,k);
             ans = ans + temp2;
             
         
        }  
        }
        return ans;
    }
};