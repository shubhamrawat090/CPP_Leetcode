/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        // First make a copy without setting random pointer
        // When making copy do this as well,
            // Create a map, origNode --> newListNode to get which node in orig list corresponds to which in the new list
        // In a second iteration(of the orig list) do this
            // Get the new list equivalent for currPtr and currPtr.random from the map
            // Set the values for newListPtr and newListPtr.random with these values

        Node* curr = head;
        Node* newDummy = new Node(0);
        Node* newCurr = newDummy;

        unordered_map<Node*, Node*> oldNewMappings;
        
        while(curr != NULL) {
            Node* newNode = new Node(curr->val);

            // Add to map
            oldNewMappings[curr] = newNode;

            newCurr->next = newNode;
            newCurr = newCurr->next;
            curr = curr->next;
        }

        curr = head;
        while(curr != NULL) {
            Node* newNode = oldNewMappings[curr];
            Node* newRandom = curr->random == NULL ? NULL : oldNewMappings[curr->random];
            newNode->random = newRandom;
            curr = curr->next;
        }

        return newDummy->next;
    }
};