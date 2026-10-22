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
    bool helper(TreeNode* root,int targetSum,int sum){
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL && sum == targetSum)
        return true;
       
      return (root->left != NULL && helper(root->left,targetSum,sum+root->left->val)) ||
      (root->right != NULL && helper(root->right,targetSum,sum+root->right->val));

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return NULL;
        int sum=root->val;
       return helper(root,targetSum,sum);
    }
};