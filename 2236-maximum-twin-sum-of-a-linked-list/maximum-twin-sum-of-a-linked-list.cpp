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
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode* curr = head;
        while(curr != NULL) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int n = arr.size();
        int left = 0, right = n-1;
        int maxSum = 0;
        while(left < right) {
            int sum = arr[left] + arr[right];
            maxSum = max(maxSum, sum);
            left++;
            right--;
        }
        return maxSum;
    }
};