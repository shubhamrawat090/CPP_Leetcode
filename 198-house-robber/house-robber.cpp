class Solution {
public:
    int rob(vector<int>& nums) {
        // return recursive(nums, 0);
        int n = nums.size();
        vector<int> dp(n, -1);
        return memoized(nums, 0, dp);
    }

    int memoized(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        // Take ith
        int take = nums[i] + memoized(nums, i+2, dp);
        // Not Take ith
        int notTake = memoized(nums, i+1, dp);
        return dp[i] = max(take, notTake);
    }

    int recursive(vector<int>& nums, int i) {
        int n = nums.size();
        if(i >= n) return 0;

        // Take ith
        int take = nums[i] + recursive(nums, i+2);
        // Not Take ith
        int notTake = recursive(nums, i+1);
        return max(take, notTake);
    }
};