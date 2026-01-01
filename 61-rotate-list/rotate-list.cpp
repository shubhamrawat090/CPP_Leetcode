/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head; // 0 nodes or 1 node or 0 rotations
        ListNode* curr = head;
        int length = 1;
        while(curr->next != NULL) {
            curr = curr->next;
            length++;
        }

        // curr points at the last node
        // orig list: 1->2->3->4->5->
        // 5--->1 in this step
        curr->next = head;

        k = k % length;
        for(int i=0; i<length-k; i++) {
            // from node 5 to get to node 3 we need to move 3 steps(n-k steps)
            curr = curr->next;
        }

        // Before breaking connection b/w nodes 3 and 4. MAKE 4 the head
        head = curr->next;
        curr->next = NULL; // break connection between nodes 3 and 4

        return head;
    }
};