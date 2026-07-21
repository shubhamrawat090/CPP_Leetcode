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
    void reorderList(ListNode* head) {
        // ALWAYS reverse from (mid->next)
        ListNode* mid = findMid(head);
        ListNode* secondHalf = mid->next;
        mid->next = NULL;
        if (secondHalf) {
            ListNode* curr = secondHalf;
            while (curr) {
                cout << curr->val << "->";
                curr = curr->next;
            }
            cout<<endl;
        }
        secondHalf = reverseList(secondHalf);
        if (secondHalf) {
            ListNode* curr = secondHalf;
            while (curr) {
                cout << curr->val << "->";
                curr = curr->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (head != NULL && secondHalf != NULL) {
            tail->next = head;
            head = head->next;
            tail = tail->next;
            tail->next = secondHalf;
            secondHalf = secondHalf->next;
            tail = tail->next;
        }

        if (head != NULL)
            tail->next = head;
        else if (secondHalf != NULL)
            tail->next = secondHalf;

        head = dummy->next;
    }

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};