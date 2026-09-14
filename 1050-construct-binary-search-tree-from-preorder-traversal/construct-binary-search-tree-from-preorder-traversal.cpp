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
TreeNode* helper(vector<int>& preorder,int& i,long long low,long long high){
      if(i == preorder.size() || preorder[i] <= low || preorder[i] >= high) return NULL;
      TreeNode* node = new TreeNode(preorder[i]);
      i++;
      node->left = helper(preorder,i,low,node->val);
      node->right = helper(preorder,i,node->val,high);
      return node;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder,i,LLONG_MIN,LLONG_MAX);
    }
};