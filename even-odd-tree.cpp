class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            int prevVal = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->val % 2 == level % 2) 
                    return false;
                if (i > 0 && ((level % 2 == 0 && node->val <= prevVal) || (level % 2 == 1 && node->val >= prevVal))) {
                    return false;
                }
                prevVal = node->val;
                if (node->left) 
                    q.push(node->left);
                if (node->right) 
                    q.push(node->right);
            }
            level++;
        }
        return true;
    }
};