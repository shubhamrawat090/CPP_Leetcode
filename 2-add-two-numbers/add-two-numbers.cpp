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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        while(l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = l1 == NULL ? 0 : l1->val;
            int val2 = l2 == NULL ? 0 : l2->val;

            int sum = val1 + val2 + carry;
            int rem = sum % 10;
            carry = sum / 10;

            temp->next = new ListNode(rem);
            temp = temp->next;

            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }

        if(carry != 0) {
            temp->next = new ListNode(carry);
        }

        return dummy->next;
    }
};