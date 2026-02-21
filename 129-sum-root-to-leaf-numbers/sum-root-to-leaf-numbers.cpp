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
        helper(root, 0);
        return ans;
    }

    void helper(TreeNode* root, int currSum) {
        if(root == NULL) {
            return;
        }
        currSum = currSum * 10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            ans += currSum;
            return;
        }
        helper(root->left, currSum);
        helper(root->right, currSum);
    }
};