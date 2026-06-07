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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> valNode;
        unordered_map<int, TreeNode*> nodeParent;

        // Initialized all with NULL
        for(auto& desc: descriptions) {
            int parent = desc[0], child = desc[1];
            nodeParent[parent] = NULL;
            nodeParent[child] = NULL;
        }

        for(auto& desc: descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            TreeNode* node;
            TreeNode* childNode;

            // GET NODE AND CHILDNODE
            if(valNode.find(parent) == valNode.end()) {
                node = new TreeNode(parent);
            } else {
                node = valNode[parent];
            }

            if(valNode.find(child) == valNode.end()) {
                childNode = new TreeNode(child);
            } else {
                childNode = valNode[child];
            }


            // CONNECT CHILD AND PARENT
            if(isLeft) {
                node->left = childNode;
            } else {
                node->right = childNode;
            }

            // Update nodes registry(map)
            valNode[parent] = node;
            valNode[child] = childNode;

            // Update parent nodes of each child
            nodeParent[child] = node;
        }

        int node = -1;
        for(auto& entry: nodeParent) {
            if(entry.second == NULL) {
                node = entry.first;
                break;
            }
        }

        return valNode[node];
    }
};