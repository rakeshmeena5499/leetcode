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
    int count;
    void solve(TreeNode* root, int maxSoFar){
        if(root==NULL)
            return;
        if(root->val >= maxSoFar)
            count++;
        solve(root->left, max(maxSoFar, root->val));
        solve(root->right, max(maxSoFar, root->val));
    }

    int goodNodes(TreeNode* root) {
        count = 0;
        int maxSoFar = INT_MIN;
        solve(root, maxSoFar);
        return count;
    }
};