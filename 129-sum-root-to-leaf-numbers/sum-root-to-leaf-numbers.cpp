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
    int ans;
public:
    int sumNumbers(TreeNode* root) {
        ans = 0;
        int sum = 0;
        helper(root, sum);
        return ans;
    }

    void helper(TreeNode* root, int sum) {
        if(root == NULL) return;
        sum = sum * 10 + root->val;
        helper(root->left, sum);
        helper(root->right, sum);
        if(root->left == NULL && root->right == NULL) {
            ans += sum;
        }
    }
};