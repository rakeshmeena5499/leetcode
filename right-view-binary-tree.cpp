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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(i==n-1)
                    res.push_back(temp->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
        }      
        return res;
    }
};


/***************DFS*****************
void solve(vector<int>& vec, TreeNode* root, int level, int& maxLevel){
    if(root==NULL)
        return;
    if(maxLevel<level){
        vec.push_back(root->val);
        maxLevel = level;
    }
    solve(vec, root->right, level+1, maxLevel);
    solve(vec, root->left, level+1, maxLevel);
}

vector<int> rightSideView(TreeNode* root){
    int maxLevel = 0;
    vector<int> res;
    solve(vec, root, 1, maxLevel);
    return res;
}
*/