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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        helper(root, sum, low, high);
        return sum;
    }

    void helper(TreeNode* root, int& sum, int low, int high) {
        if(root == NULL) {
            return;
        }
        
        if(root->val >= low && root->val <= high) {
            sum += root->val;
        }

        // go left only when there are possible values in left within range
        if(root->val > low) {
            helper(root->left, sum, low, high);
        }
        // go right only when there are possible values in left within range
        if(root->val < high) {
            helper(root->right, sum, low, high);
        }
    }
};