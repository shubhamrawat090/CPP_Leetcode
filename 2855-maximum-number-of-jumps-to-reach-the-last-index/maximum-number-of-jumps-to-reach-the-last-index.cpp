class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n + 1, -2);
        return helper(nums, target, n - 1, dp);
    }

    int helper(vector<int>& nums, int& target, int endPt, vector<int>& dp) {
        if (endPt == 0)
            return 0;
        if (endPt == 1) {
            int diff = nums[1] - nums[0];
            if (diff >= -target && diff <= target) {
                return 1; // 1 jump if within target
            } else {
                return -1; // Cannot reach
            }
        }

        if (dp[endPt] != -2)
            return dp[endPt];

        int maxJumps = -1;
        for (int i = 0; i < endPt; i++) {
            int diff = nums[endPt] - nums[i];
            if (diff >= -target && diff <= target) {
                int jumpsTill_I = helper(nums, target, i, dp);
                if (jumpsTill_I != -1) {
                    maxJumps = max(maxJumps, 1 + jumpsTill_I);
                }
            }
        }

        return dp[endPt] = maxJumps;
    }
};