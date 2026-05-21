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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int k = lists.size();
        for(int i=0; i<k; i++) {
            if(lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();
            tail->next = top;
            top = top->next;
            tail = tail->next;
            if(top != NULL) {
                minHeap.push(top);
            }
        }
        return dummy->next;
    }
};