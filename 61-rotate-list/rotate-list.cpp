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
        if(head == NULL || head->next == NULL || k == 0) return head;
        int length = 0;
        ListNode* curr = head;
        ListNode* tail;

        while(curr != NULL) {
            length++;
            if(curr->next == NULL) tail = curr;
            curr = curr->next;
        }

        if(length == 0) return NULL;

        k = k%length; // k rotations is orig array
        if(k == 0) return head;

        curr = head;
        for(int i=1; i<length-k; i++) {
            curr = curr->next;
        }

        ListNode* origHead = head;
        head = curr->next;
        curr->next = NULL;
        tail->next = origHead;

        return head;
    }
};