class Solution {
public:
    int sum;
    void solve(TreeNode* root, int curr){
        curr = curr*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            sum += curr;
        }
        if(root->left!=NULL){
            solve(root->left, curr);
        }
        if(root->right!=NULL){
            solve(root->right, curr);
        }
    }

    int sumNumbers(TreeNode* root) {
        sum = 0;
        solve(root, 0);
        return sum;
    }
};