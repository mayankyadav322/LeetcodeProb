/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int s = q.size();
            vector<int> res(s);
            for(int i=0;i<s;i++){
             TreeNode* node = q.front();
             q.pop();
             if(level ==0){
                res[i] = node->val;
             }
             else{
                res[s-i-1]= node->val;
             }
             if(node->left) q.push(node->left);
             if(node->right) q.push(node->right);
            }
           ans.push_back(res);
           level =! level;
        }
        
   return ans;
    }
};