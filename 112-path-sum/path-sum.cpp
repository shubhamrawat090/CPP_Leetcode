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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = false;
        helper(root, sum, ans, targetSum);
        return ans;
    }

    void helper(TreeNode* root, int sum, bool& ans, int targetSum) {
        if(root == NULL) return;
        sum += root->val;
        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) {
                ans = true;
            }
        }
        helper(root->left, sum, ans, targetSum);
        helper(root->right, sum, ans, targetSum);
    }
};