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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        deque<TreeNode*> q;
        q.push_back(root);
        int depth = 0;
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            for(int i=0;i<n;i++){
                if(depth%2==0){
                    TreeNode* temp = q.front();
                    q.pop_front();
                    level.push_back(temp->val);
                    if(temp->left!=NULL)
                        q.push_back(temp->left);
                    if(temp->right!=NULL)
                        q.push_back(temp->right);
                }
                else{
                    TreeNode* temp = q.back();
                    q.pop_back();
                    level.push_back(temp->val);
                    if(temp->right!=NULL)
                        q.push_front(temp->right);
                    if(temp->left!=NULL)
                        q.push_front(temp->left);
                }
            }
            res.push_back(level);
            depth += 1;
        }
        return res;
    }
};