/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
          
                TreeNode* node = q.front();
                q.pop();
                if(node == NULL){
                    s = s + "#,";
                    continue;
                }
                s= s + to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);       
        }
        return s;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if(data == "") return NULL;

    stringstream ss(data);
    string x;

    getline(ss, x, ',');
    TreeNode* root = new TreeNode(stoi(x));

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        getline(ss, x, ',');
        if(x != "#") {
            node->left = new TreeNode(stoi(x));
            q.push(node->left);
        }

        getline(ss, x, ',');
        if(x != "#") {
            node->right = new TreeNode(stoi(x));
            q.push(node->right);
        }
    }

    return root;
}
};