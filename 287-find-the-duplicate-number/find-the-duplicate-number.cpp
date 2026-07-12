class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Example:

        // nums = [1,3,4,2,2]

        // Index: 0 1 2 3 4
        // Value: 1 3 4 2 2

        // The linked list becomes:

        // 0 -> 1 -> 3 -> 2 -> 4
        //           ^         |
        //           |_________|

        // The duplicate value (2) causes two indices to point to the same node, creating a cycle.

        // Phase 1: Find meeting point
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(fast != slow);

        // Phase 2: Find cycle entrance
        slow = 0;
        while(fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};