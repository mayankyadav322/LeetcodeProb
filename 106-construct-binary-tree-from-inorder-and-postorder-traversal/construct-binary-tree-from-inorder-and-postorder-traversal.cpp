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
int search(vector<int>& inorder,int left,int right,int val){
    for(int i=left;i<=right;i++){
        if(inorder[i] == val) return i;
    }
    return -1;
}
    TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int& posidx,int left,int right){
        if(left > right) return NULL;
        TreeNode* node = new TreeNode(postorder[posidx]);
        posidx--;
        int indx = search(inorder,left,right,node->val);
       
        node->right = helper(inorder,postorder,posidx,indx+1,right);
         node->left = helper(inorder,postorder,posidx,left,indx-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posidx = postorder.size()-1;
       return helper(inorder,postorder,posidx,0,inorder.size()-1);
    }
};