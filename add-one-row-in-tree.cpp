class Solution {
public:
    void solve(TreeNode* root, int curr, int val, int depth){
        if(root==NULL){
            return;
        }
        if(curr == depth - 1){
            TreeNode* tempLeft = new TreeNode(val);
            tempLeft->left = root->left;
            root->left = tempLeft;
            
            TreeNode* tempRight = new TreeNode(val);
            tempRight->right = root->right;
            root->right = tempRight;
        }
        solve(root->left, curr+1, val, depth);
        solve(root->right, curr+1, val, depth);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        int curr = 1;
        solve(root, curr, val, depth);
        return root;   
    }
};