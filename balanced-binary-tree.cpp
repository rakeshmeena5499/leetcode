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
    bool solve(TreeNode* root, int& height){
        if(root==NULL){
            height = -1;
            return true;
        }
        int left = 0, right = 0;
        if(!solve(root->left, left) || !solve(root->right, right))
            return false;
        if(abs(left-right)>1)
            return false;
        height = max(left, right) + 1;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return solve(root, height);
    }
};