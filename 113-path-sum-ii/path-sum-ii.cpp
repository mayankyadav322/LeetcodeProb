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
    void helper(TreeNode* root,int targetSum,vector<int>& current,vector<vector<int>>& ans,int sum){
       if(root == NULL) return ;
       current.push_back(root->val);
       sum = sum + root->val;
       if(root->left == NULL && root->right == NULL && sum == targetSum){
        ans.push_back(current);
        
       }
       
       helper(root->left,targetSum,current,ans,sum);
       helper(root->right,targetSum,current,ans,sum);
       current.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> current;
        vector<vector<int>> ans;
        int sum = 0;
         helper(root,targetSum,current,ans,sum);
        return ans;
    }
};