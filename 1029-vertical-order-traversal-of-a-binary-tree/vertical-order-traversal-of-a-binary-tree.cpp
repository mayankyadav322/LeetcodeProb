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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,map<int,vector<int> > > f;
        queue<pair<TreeNode*,pair<int,int> > > q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> frontnode = q.front();
            q.pop();
            TreeNode* temp = frontnode.first;
            int lvl = frontnode.second.first;
            int hd = frontnode.second.second;
            f[hd][lvl].push_back(temp->val);
            if(temp->left) q.push(make_pair(temp->left,make_pair(lvl+1,hd-1)));
            if(temp->right) q.push(make_pair(temp->right,make_pair(lvl+1,hd+1)));


        }
        for(auto i:f){
            vector<int> m;
            for(auto j:i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k:j.second){
                    m.push_back(k);
                }
            }
            res.push_back(m);
        }

   return res;
    }
};