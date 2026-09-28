class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int result =0;
        int count =0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push('(');
                count++;
            }
            else if(s[i] == ')'){
                st.pop();
                count--;
            }
            result = max(count,result);
                
            
        }
        return result;
    }
};