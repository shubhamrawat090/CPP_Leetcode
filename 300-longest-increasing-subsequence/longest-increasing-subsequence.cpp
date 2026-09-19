class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // return recursive(nums, 0, -1);
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return memoized(nums, 0, -1, dp);
        return tabulate(nums);
    }

    int tabulate(vector<int>& nums) {
        int n = nums.size();
        // i -> 0 --> n-1
        // prevIdx -> -1 -> n-1
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int prevIdx = n - 2; prevIdx >= -1; prevIdx--) {
                // not take
                int len = 0 + dp[i + 1][prevIdx + 1];
                // take - ONLY WHEN prevVal < currVal
                if (prevIdx == -1 || nums[prevIdx] < nums[i]) {
                    // YEH ELEM LIYA HAI ==> prevIdx = i
                    len = max(len, 1 + dp[i + 1][i + 1]);
                }

                dp[i][prevIdx + 1] = len;
            }
        }

        return dp[0][0];
    }

    int memoized(vector<int>& nums, int i, int prevIdx,
                 vector<vector<int>>& dp) {
        int n = nums.size();
        if (i == n) {
            return 0;
        }

        if (dp[i][prevIdx + 1] != -1) {
            return dp[i][prevIdx + 1];
        }

        // not take
        int len = 0 + memoized(nums, i + 1, prevIdx, dp);
        // take - ONLY WHEN prevVal < currVal
        if (prevIdx == -1 || nums[prevIdx] < nums[i]) {
            // YEH ELEM LIYA HAI ==> prevIdx = i
            len = max(len, 1 + memoized(nums, i + 1, i, dp));
        }

        return dp[i][prevIdx + 1] = len;
    }

    int recursive(vector<int>& nums, int i, int prevIdx) {
        int n = nums.size();
        if (i == n) {
            return 0;
        }

        // not take
        int len = 0 + recursive(nums, i + 1, prevIdx);
        // take - ONLY WHEN prevVal < currVal
        if (prevIdx == -1 || nums[prevIdx] < nums[i]) {
            // YEH ELEM LIYA HAI ==> prevIdx = i
            len = max(len, 1 + recursive(nums, i + 1, i));
        }

        return len;
    }
};