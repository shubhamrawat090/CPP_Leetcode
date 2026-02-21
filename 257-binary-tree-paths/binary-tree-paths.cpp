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
    vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        ans = {};
        string path;
        helper(root, path);
        return ans;
    }

    void helper(TreeNode* root, string path) {
        if(root == NULL) {
            return;
        }

        path += to_string(root->val);

        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
        }
        path += "->";

        helper(root->left, path);
        helper(root->right, path);
    }
};