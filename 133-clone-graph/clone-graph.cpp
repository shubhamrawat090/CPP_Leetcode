/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        vector<Node*> values(101, NULL);
        return helper(node, values);
    }

    Node* helper(Node* node,  vector<Node*>& values) {
        if(node == NULL) return NULL;
        if(values[node->val] != NULL) return values[node->val];

        Node* newNode = new Node();
        newNode->val = node->val;
        values[newNode->val] = newNode;

        for(Node* nbr: node->neighbors) {
            Node* nbrNode = helper(nbr, values);
            newNode->neighbors.push_back(nbrNode);
        } 

        return newNode;
    }
};