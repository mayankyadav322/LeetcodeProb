class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(stoi(tokens[i]));
            }
            else{
                int ans = st.top();
                st.pop();
                int result;
                 if(tokens[i] == "+"){
                 result = st.top() + ans;
                 }
                else if(tokens[i] == "-"){
                 result = st.top() - ans;
                 }
                else if(tokens[i] == "*"){
                 result = st.top() * ans;
                 }
                else if(tokens[i] == "/"){
                 result = st.top() / ans;
                 }
                st.pop();
                st.push(result);
            }
        }
        return st.top();
    }
};