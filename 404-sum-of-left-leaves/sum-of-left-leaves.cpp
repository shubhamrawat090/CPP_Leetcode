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
    int ans = 0;

public:
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return ans;
    }

    void helper(TreeNode* root) {
        if (root == NULL)
            return;
        if (root->left != NULL && root->left->left == NULL &&
            root->left->right == NULL)
            ans += root->left->val;
        helper(root->left);
        helper(root->right);
    }
};