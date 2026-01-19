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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int sum = 0;
        helper(root, sum, ans);
        return ans;
    }

    void helper(TreeNode* root, int sum, int& ans) {
        if(root == NULL) return;
        sum = sum * 10 + root->val;
        helper(root->left, sum, ans);
        helper(root->right, sum, ans);
        if(root->left == NULL && root->right == NULL) {
            ans += sum;
        }
    }
};