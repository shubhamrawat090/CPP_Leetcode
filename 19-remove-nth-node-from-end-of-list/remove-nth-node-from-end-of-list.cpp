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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // If only 1 node then return an empty list
        if(head->next == NULL || head == NULL) return NULL;

        // count no. of nodes => if same as head then remove head only
        ListNode* ptr = head;
        for(int i=0; i<n && ptr != NULL; i++) {
            ptr = ptr->next;
        }
        if(ptr == NULL) return head->next;

        ListNode* leftPtr = head;
        ListNode* rightPtr = head;


        for(int i=0; i<n; i++) { // place right ptr n positions ahead
            rightPtr = rightPtr->next;
        }

        while(rightPtr != NULL && rightPtr->next != NULL) {
            leftPtr = leftPtr->next;
            rightPtr = rightPtr->next;
        }
        ListNode* removedPtr = leftPtr->next;
        leftPtr->next = leftPtr->next->next;

        delete removedPtr;
        return head;
    }
};