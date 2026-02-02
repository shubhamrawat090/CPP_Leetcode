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
    TreeNode* trimBST(TreeNode* root, int l, int r) {
        // Your code here
        if(!root)return nullptr;
        int data = root->val;
        if(data>=l and data<=r){
            root->left = trimBST(root->left,l,r);
            root->right = trimBST(root->right,l,r);
        }else if(data < l){
            root->left = nullptr;
            root = trimBST(root->right,l,r);
        }
        else{
            root->right = nullptr;
            root = trimBST(root->left,l,r);
        }
        return root;
    }
};