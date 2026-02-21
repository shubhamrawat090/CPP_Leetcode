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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()) {
            long long size = q.size();
            long long index = q.front().second;
            long long first = 0, last = 0;
            for(long long i=0; i<size; i++) {
                auto top = q.front(); q.pop();
                long long currIdx = top.second - index;
                TreeNode* currNode = top.first;
                if(i == 0) first = currIdx;
                if(i == size-1) last = currIdx;
                if(currNode->left != NULL) {
                    q.push({currNode->left, 2 * currIdx + 1});
                }
                if(currNode->right != NULL) {
                    q.push({currNode->right, 2 * currIdx + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};