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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> uniqueNums;
        for(int num: nums) {
            uniqueNums.insert(num);
        }

        ListNode* ans = new ListNode();
        ListNode* ansTail = ans;
        ListNode* temp = head;
        while(temp != NULL) {
            if(uniqueNums.find(temp->val) == uniqueNums.end()) {
                ansTail->next = new ListNode(temp->val);
                ansTail = ansTail->next;
            }
            temp = temp->next;
        }
        return ans->next;
    }
};