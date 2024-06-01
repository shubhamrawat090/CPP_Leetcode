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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ansHead = new ListNode();
        ListNode* ansTail = ansHead;

        while(list1 != NULL && list2 != NULL) {
            int val1 = list1->val;
            int val2 = list2->val;

            if(val1 < val2) { // take from 1
                ansTail->next = list1;
                list1 = list1->next;
            } else { // take from 2
                ansTail->next = list2;
                list2 = list2->next;     
            }
            ansTail = ansTail->next;
        }

        if(list1 != NULL) ansTail->next = list1;
        else if(list2 != NULL) ansTail->next = list2;

        return ansHead->next;
    }
};