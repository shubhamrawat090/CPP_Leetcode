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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

    TreeNode* helper(vector<int>& nums, int low, int high) {
        if(low > high) return NULL;

        int mid = (low + high) / 2;

        TreeNode* leftHead = helper(nums, low, mid-1);
        TreeNode* rightHead = helper(nums, mid+1, high);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = leftHead;
        root->right = rightHead;
        return root;
    }
};