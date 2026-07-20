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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* ptr = curr->next;
            while(ptr != NULL && curr->val == ptr->val) {
                ListNode* temp = ptr;
                ptr = ptr->next;
                // OPTIONAL: Free node memory
                temp->next = NULL; // unlink node 
                delete temp;
            }
            curr->next = ptr;
            curr = curr->next;
        }
        return head;
    }
};