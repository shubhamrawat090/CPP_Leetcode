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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *leftEnd = NULL, *rightEnd = NULL;
        ListNode *start = head, *end = head;
        for (int i = 1; i < right; i++) {
            if (start == NULL || end == NULL)
                break;
            if (i < left) {
                leftEnd = start;
                start = start->next;
            }
            end = end->next;
        }
        rightEnd = end->next;

        ListNode* prev = rightEnd;
        ListNode* curr = start;

        while (curr != NULL && curr != rightEnd) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if (leftEnd != NULL) {
            leftEnd->next = end;
        } else {
            head = end;
        }

        return head;
    }
};