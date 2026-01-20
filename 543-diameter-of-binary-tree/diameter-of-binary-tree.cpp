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
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        helper(root);
        return diameter;
    }

    void helper(TreeNode* root) {
        if(root == NULL) return;
        int dia = height(root->left) + height(root->right);
        diameter = max(diameter, dia);
        helper(root->left);
        helper(root->right);
    }

    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};