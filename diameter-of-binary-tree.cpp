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
    int height(TreeNode* root, int& res){
        if(root==NULL)
            return 0;
        int left_height = height(root->left, res);
        int right_height = height(root->right, res);
        res = max(res, left_height + right_height);
        return 1+max(left_height, right_height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        height(root, res);
        return res;    
    }
};