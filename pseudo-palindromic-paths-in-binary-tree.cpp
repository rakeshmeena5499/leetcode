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
    void preorder(TreeNode* root, int path, int& count){
        if(root!=NULL){
            path = path ^ (1<<root->val-1);                 // Keep on XORing the values of nodes
            if(root->left == NULL && root->right == NULL){  // When we reach leaf nodes check if its 
                if((path & (path - 1)) == 0){               // the only value with odd occurances
                    count++;
                }
            }
            preorder(root->left, path, count);
            preorder(root->right, path, count);
        }
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL)
            return 0;
        int path = 0;
        int count = 0;
        preorder(root, path, count);
        return count;
    }
};