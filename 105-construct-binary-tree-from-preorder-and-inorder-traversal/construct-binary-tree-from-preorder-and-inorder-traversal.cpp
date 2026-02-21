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
    int preorderIdx;
    unordered_map<int, int> inorderValIdx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIdx = 0;
        inorderValIdx = {};
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            inorderValIdx[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, n-1);
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if(left > right) {
            return NULL;
        }
        int rootVal = preorder[preorderIdx];
        preorderIdx++;

        TreeNode* root = new TreeNode(rootVal);
        int rootInorderIdx = inorderValIdx[rootVal];
        root->left = helper(preorder, inorder, left, rootInorderIdx-1);
        root->right = helper(preorder, inorder, rootInorderIdx+1, right);
        return root;
    }
};