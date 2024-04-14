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
    int sum;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            if(!root->left->left && !root->left->right)
            sum+=root->left->val;
        }
        solve(root->left);
        solve(root->right);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        solve(root);
        return sum;
    }
};