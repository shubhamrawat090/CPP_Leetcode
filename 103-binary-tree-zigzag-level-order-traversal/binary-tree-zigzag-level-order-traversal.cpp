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
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int> levelItems;
            for(int i=0; i<size; i++) {
                TreeNode* top = q.front(); q.pop();
                levelItems.push_back(top->val);
                if(top->left) {
                    q.push(top->left);
                }
                if(top->right) {
                    q.push(top->right);
                }
            }
            if(level % 2 != 0) {
                reverse(levelItems.begin(), levelItems.end());
            }
            ans.push_back(levelItems);
            level++;
        }
        return ans;
    }
};