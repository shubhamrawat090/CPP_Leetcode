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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currPath;
        vector<vector<int>> ans;
        helper(root, ans, currPath, targetSum, 0);
        return ans;
    }

    void helper(TreeNode* root, vector<vector<int>>& ans, vector<int> currPath, int targetSum, int sum) {
        if(root == NULL) return;
        sum += root->val;
        currPath.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) {
                ans.push_back(currPath);
            }
        }
        helper(root->left, ans, currPath, targetSum, sum);
        helper(root->right, ans, currPath, targetSum, sum);
    }
};