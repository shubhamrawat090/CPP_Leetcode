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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int count = 0;
        long long sum = 0;
        count += helper(root, targetSum, sum);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }

    int helper(TreeNode* root, int targetSum, long long sum) {
        if(root == NULL) return 0;
        int count = 0;
        sum += root->val;
        if(sum == targetSum) count++;
        count += helper(root->left, targetSum, sum);
        count += helper(root->right, targetSum, sum);
        return count;
    }
};