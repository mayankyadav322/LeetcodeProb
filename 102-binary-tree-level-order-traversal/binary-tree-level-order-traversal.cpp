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
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> v;
       queue<TreeNode*> qv;
       qv.push(root);
       if(root == NULL) return v;
       while(!qv.empty()){
        int x = qv.size();
        vector<int> v1;
        while(x--){
            TreeNode* front =qv.front();
            qv.pop();
            if(front->left != NULL){
                qv.push(front->left);
            } 
             if(front->right != NULL){
                qv.push(front->right);
            } 
            v1.push_back(front->val);
        }
         v.push_back(v1);
       } 
      return v;
    }
};