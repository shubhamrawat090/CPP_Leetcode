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
        ListNode* tail = dummy;
        
        while(l1 != NULL || l2 != NULL || carry != 0) {
            int v1 = l1 == NULL ? 0 : l1->val;
            int v2 = l2 == NULL ? 0 : l2->val;

            int sum = (v1 + v2 + carry);
            
            carry = sum / 10;
            
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        
        return dummy->next;
    }
};