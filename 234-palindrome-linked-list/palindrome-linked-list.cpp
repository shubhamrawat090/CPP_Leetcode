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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        int size = sizeOfLL(head);
        ListNode* mid = middleNode(head);
        ListNode* revListHead = size % 2 == 0 ? mid : mid->next;
        revListHead = reverseList(revListHead);

        ListNode* curr = head;
        ListNode* revCurr = revListHead;
        while(curr != NULL && revCurr != NULL) {
            if(curr->val != revCurr->val) return false;
            curr = curr->next;
            revCurr = revCurr->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* currNode = curr;
            curr = curr->next;
            currNode->next = prev;
            prev = currNode;
        }
        return prev;
    }

    int sizeOfLL(ListNode* head) {
        ListNode* curr = head;
        int size = 0;
        while(curr != NULL) {
            size++;
            curr = curr->next;
        }
        return size;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};