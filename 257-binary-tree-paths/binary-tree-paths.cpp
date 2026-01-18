/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> row;
        helper(root, ans, row);
        return ans;
    }

    void helper(TreeNode* root, vector<string>& ans, vector<int> row) {
        if (root == NULL)
            return;
        row.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            string path;
            for (int i = 0; i < row.size(); i++) {
                int val = row[i];
                path += to_string(val);
                if (i != row.size() - 1)
                    path += "->";
            }
            ans.push_back(path);
        }
        helper(root->left, ans, row);
        helper(root->right, ans, row);
    }
};