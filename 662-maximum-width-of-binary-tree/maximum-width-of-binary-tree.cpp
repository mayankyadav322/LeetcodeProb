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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
                queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        long long ans =0;
        while(!q.empty()){
            long long n=q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            ans = max(ans,end-start+1);
            for(int i=0;i<n;i++){
                pair<TreeNode*,int> node=q.front();
                TreeNode* value = node.first;
                long long idx = node.second;
                q.pop();
                if(value->left) q.push({value->left,2*idx+1});
                if(value->right) q.push({value->right,2*idx+2});
            }
        }
        return ans;
    }
};