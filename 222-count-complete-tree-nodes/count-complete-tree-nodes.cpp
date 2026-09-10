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
int findheightleft(TreeNode* root){
    int higt = 0;
    while(root){
        higt++;
        root = root->left;
    }
    return higt;
}
int findheightright(TreeNode* root){
    int higt = 0;
    while(root){
        higt++;
         root = root->right;
    }
    return higt;
}
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lf = findheightleft(root);
        int rh = findheightright(root);
        if(lf == rh) return (1 << lf)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};