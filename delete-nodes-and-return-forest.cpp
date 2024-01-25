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
    void solve(TreeNode*& root, unordered_set<int>& st, vector<TreeNode*>& res){
        if(root!=NULL){
            solve(root->left, st, res);
            solve(root->right, st, res);
            if(st.find(root->val)!=st.end()){
                if(root->left!=NULL){
                    res.push_back(root->left);
                }
                if(root->right!=NULL){
                    res.push_back(root->right);
                }
                root = NULL;
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        solve(root, st, ans);
        if(root)
            ans.push_back(root);
        return ans;
    }
};