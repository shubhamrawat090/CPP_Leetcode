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
        if(head == NULL) return head;
        int size = 0;
        ListNode *curr = head;
        while(curr != NULL) {
            curr = curr->next;
            size++;
        }
        if(size < n) return head;

        if(size == n) {
            // remove from head;
            head = head->next;
            return head;
        }
        ListNode *s1 = head, *s2 = head;
        for(int i=0; i<n; i++) {
            s2 = s2->next;
        }

        while(s2->next != NULL) {
            s1 = s1->next;
            s2 = s2->next;
        }

        s1->next = s1->next->next;
        return head;
    }
};