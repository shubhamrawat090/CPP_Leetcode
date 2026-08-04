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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        dummy->next = head;
        
        while(curr!=NULL && curr->next!=NULL){
            // 1. 
            prev->next = curr->next;
            
            // 2.
            curr->next = curr->next->next;
            
            // 3.
            prev->next->next = curr;
            
            //update curr and prev
            prev = curr; // same as prev->next->next as curr isn't updated yet
            curr = curr->next;
        }
        
        return dummy->next;
    }
};