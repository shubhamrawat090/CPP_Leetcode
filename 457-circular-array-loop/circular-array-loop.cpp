class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // TRY ALL INDICES AS STARTING POINT
            bool forwardDirection = (nums[i] > 0);
            int slow = i, fast = i;
            do {
                // Jahan se aya hu --> jahan pahucha hu ==> SHOULD BE DIFFERENT
                // Otherwise 1 size cycle
                int prevSlow = slow;
                slow = move(nums, slow, nums[slow]);
                if (slow == prevSlow)
                    break;
                bool currDir = (nums[slow] > 0);
                if(currDir != forwardDirection) {
                    break;
                }

                int prevFast = fast;
                fast = move(nums, fast, nums[fast]);
                if (fast == prevFast)
                    break;
                currDir = (nums[fast] > 0);
                if(currDir != forwardDirection) {
                    break;
                }

                prevFast = fast;
                fast = move(nums, fast, nums[fast]);
                if (fast == prevFast)
                    break;
                currDir = (nums[fast] > 0);
                if(currDir != forwardDirection) {
                    break;
                }

                if (slow == fast)
                    return true;
            } while (true);
        }
        return false;
    }

    int move(vector<int>& nums, int pos, int steps) {
        int n = nums.size();
        int newPos = pos;
        if (steps > 0) {
            newPos = (pos + steps) % n;
        } else if (steps < 0) {
            // to make -ve to positive. Just add it to n
            newPos = move(nums, pos, n + steps);
        }
        return newPos;
    }
};