class Solution {
public:
long long solver(vector<vector<int>>& questions,int index,vector<long long>& dp){
    if(index >= questions.size())
    return 0;
    if(dp[index] != -1)
    return dp[index];
    long long nextindex = index + questions[index][1]+1;
    long long include = questions[index][0] + solver(questions,nextindex,dp);
    long long exclude = solver(questions,index+1,dp);
   return dp[index] = max(include,exclude);
}
    long long mostPoints(vector<vector<int>>& questions) {

       int n = questions.size();
       int index = 0;
       vector<long long> dp(n+1,-1);
     return  solver(questions,index,dp);

    }
};