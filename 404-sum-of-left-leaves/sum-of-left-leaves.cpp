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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        // root is NOT NULL and has ONLY left leaf node
        int currSum = 0;
        if (root->left != NULL && root->left->left == NULL &&
            root->left->right == NULL) {
            currSum = root->left->val;
        }
        int leftSum = sumOfLeftLeaves(root->left);
        int rightSum = sumOfLeftLeaves(root->right);
        return currSum + leftSum + rightSum;
    }
};