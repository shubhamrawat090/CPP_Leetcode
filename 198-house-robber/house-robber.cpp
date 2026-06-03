class Solution {
public:
    int rob(vector<int>& nums) {
        // return recursive(nums, 0);
        // int n = nums.size();
        // vector<int> dp(n, -1);
        // return memoized(nums, 0, dp);
        // return tabulate(nums);
        return spaceOptimize(nums);
    }

    int spaceOptimize(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
            
        int prev = nums[0], prev2 = nums[0];
        if (n > 1)
            prev = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            // Take ith
            int take = nums[i] + prev2;
            // Not Take ith
            int notTake = prev;
            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int tabulate(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        if (n > 1)
            dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            // Take ith
            int take = nums[i] + dp[i - 2];
            // Not Take ith
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }

    int memoized(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Take ith
        int take = nums[i] + memoized(nums, i + 2, dp);
        // Not Take ith
        int notTake = memoized(nums, i + 1, dp);
        return dp[i] = max(take, notTake);
    }

    int recursive(vector<int>& nums, int i) {
        int n = nums.size();
        if (i >= n)
            return 0;

        // Take ith
        int take = nums[i] + recursive(nums, i + 2);
        // Not Take ith
        int notTake = recursive(nums, i + 1);
        return max(take, notTake);
    }
};