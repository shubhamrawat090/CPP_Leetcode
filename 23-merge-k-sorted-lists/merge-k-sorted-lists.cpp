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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;
        if(k == 1) return lists[0];
        ListNode* mergedList = mergeTwoLists(lists[0], lists[1]);

        for(int i=2; i<k; i++) {
            mergedList = mergeTwoLists(mergedList, lists[i]);
        }

        return mergedList;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != NULL) {
            temp->next = list1;
        } else if (list2 != NULL) {
            temp->next = list2;
        }
        return dummy->next;
    }
};