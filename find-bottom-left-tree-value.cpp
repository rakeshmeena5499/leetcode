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
    int maxDepth;
    int maxLeftValue;
    void solve(TreeNode* root, int depth){
        if(root==NULL)
            return;
        if(depth > maxDepth){
            maxDepth = depth;
            maxLeftValue = root->val;
        }
        solve(root->left, depth+1);
        solve(root->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        maxLeftValue = 0;
        solve(root, 0);
        return maxLeftValue;

    //    queue<TreeNode*> q;
    //    q.push(root);
    //    TreeNode* temp = NULL;
    //    while(!q.empty()){
    //        temp = q.front();
    //        q.pop();
    //        if(temp->right!=NULL){    // Go from the right side so that 
    //            q.push(temp->right);  // at the end we've left most value
    //        }
    //        if(temp->left!=NULL){
    //            q.push(temp->left);
    //        }
    //    } 
    //    return temp->val;
    }
};