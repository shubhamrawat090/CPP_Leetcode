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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;
        if (k == 1)
            return lists[0];

        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;
            top = top->next;

            if (top != NULL) {
                pq.push(top);
            }
        }

        return dummy->next;
    }
};