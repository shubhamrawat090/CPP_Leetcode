class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int start = 0; start < n; start++) {

            bool forward = nums[start] > 0;
            int slow = start;
            int fast = start;

            while (true) {

                slow = next(nums, slow, forward);
                if (slow == -1)
                    break;

                fast = next(nums, fast, forward);
                if (fast == -1)
                    break;

                fast = next(nums, fast, forward);
                if (fast == -1)
                    break;

                if (slow == fast)
                    return true;
            }
        }

        return false;
    }

private:
    int next(vector<int>& nums, int curr, bool forward) {

        // Direction changed
        if ((nums[curr] > 0) != forward)
            return -1;

        int n = nums.size();
        int nxt = (curr + nums[curr]) % n;

        if (nxt < 0)
            nxt += n;

        // Self loop
        if (nxt == curr)
            return -1;

        return nxt;
    }
};