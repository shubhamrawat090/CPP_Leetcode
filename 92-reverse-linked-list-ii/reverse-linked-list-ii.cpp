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

        // printVal(start, "start");
        // printVal(end, "end");

        ListNode* prev = rightEnd;
        ListNode* curr = start;

        // printVal(prev, "prev");
        // printVal(curr, "curr");
        while (curr != NULL && curr != rightEnd) {
            // cout<<"\nRunning: "<<endl;
            // printVal(curr, "curr");
            // printVal(curr->next, "curr->next");
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // printVal(leftEnd, "leftEnd");
        // NOTE: MOST IMPORTANT CONDITION
        if (leftEnd != NULL) {
            leftEnd->next = end;
        } else {
            head = end;
        }

        return head;
    }

    void printVal(ListNode* node, string name) {
        if (node) {
            cout << name << ": " << node->val << endl;
        }
    }
};