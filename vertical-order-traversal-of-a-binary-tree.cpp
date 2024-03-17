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
    map<int, vector<pair<int, int>>> mp;
    void solve(TreeNode* root, int x, int y){
        if(!root)
            return;
        mp[x].push_back({y, root->val});
        if(root->left!=NULL){
            solve(root->left, x-1, y+1);
        }
        if(root->right!=NULL){
            solve(root->right, x+1, y+1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        mp.clear();
        vector<vector<int>> res;
        if (!root)
            return res;
        solve(root, 0, 0);
        for(auto it : mp){
            auto& vec = it.second;
            sort(vec.begin(), vec.end());
            vector<int> col;
            for (auto& p : vec) {
                col.push_back(p.second);
            }
            res.push_back(col);
        }
        return res;
    }
};