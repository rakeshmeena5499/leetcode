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
    TreeNode* helper(TreeNode* root){
        if(root==NULL)
            return NULL;
        TreeNode* leftList = helper(root->left);
        TreeNode* rightList = helper(root->right);
        if(leftList){
            leftList->right = root->right;  // Goes to left most subtree and make it in 
            root->right = root->left;       // the form of right skewed binary tree
            root->left = NULL;
        }
        if(rightList){                      // Returning right most list first if not null 
            return rightList;               // as we want our linked list in form of skewed binary tree
        }
        else if(leftList){
            return leftList;
        }
        return root;
    }

    void flatten(TreeNode* root) {
        helper(root);
    }
};